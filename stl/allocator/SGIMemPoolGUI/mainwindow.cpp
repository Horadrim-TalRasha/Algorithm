#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fillMemPoolInfoWidget();
    updateHeapSize();
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(memAllocSlot()));
}

void MainWindow::fillMemPoolInfoWidget()
{
    int freeListNum = (int)__NFREELISTS;
    for(int i = 0; i < freeListNum; ++i)
    {
        char * memIdx = (char *)*(default_allocator::free_list + default_allocator::FREELIST_INDEX(i));
        QTreeWidgetItem * indexItem = new QTreeWidgetItem();
        indexItem->setText(0, QString("%1(%2 bytes)").arg(i).arg((i + 1) * __ALIGN));
        indexItem->setText(1, QString().setNum((long)memIdx, 16).prepend("0x"));
        ui->treeWidget->addTopLevelItem(indexItem);
    }
}

void MainWindow::memAllocSlot()
{
    size_t requiredMemSize = (size_t)ui->spinBox->value();
    if(requiredMemSize == 0)
    {
        return;
    }
    else
    {
        char * p = (char *)default_allocator::allocate(requiredMemSize);
        if(p == NULL)
        {
            return;
        }

        m_allocatedMemBlocks.insert(p, requiredMemSize);
        updateMemPoolInfoWidget(default_allocator::FREELIST_INDEX(requiredMemSize), p);
        updateHeapSize();
        updateMemoryPoolUsage();
    }
}

void MainWindow::updateMemPoolInfoWidget(const size_t & index, char * allocatedAddr)
{
    std::cout << "heap size: " << std::dec << default_allocator::heap_size << std::endl;
    std::cout << "start address: 0x" << std::hex << (long)default_allocator::start_free << std::endl;
    std::cout << "end address: 0x" << std::hex << (long)default_allocator::end_free << std::endl;

    QTreeWidgetItem * targetItem = ui->treeWidget->topLevelItem((int)index);
    default_allocator::obj * targetFreeList = *(default_allocator::free_list + index);
    default_allocator::obj * nextObj = NULL;
    assert(targetItem != 0);

    if(removeExcessItemWhenAllocated(targetItem, allocatedAddr))
    {
        return;
    }


    while(targetFreeList != NULL  &&
          (nextObj = targetFreeList->free_list_link) != NULL)
    {
        QTreeWidgetItem * curItem = new QTreeWidgetItem();
        curItem->setText(0, QString().setNum((long)targetFreeList, 16).prepend("0x"));
        curItem->setText(1, QString().setNum((long)nextObj, 16).prepend("0x"));
        targetItem->addChild(curItem);
        targetFreeList = nextObj;
    }

    QTreeWidgetItem * lastItem = new QTreeWidgetItem();
    lastItem->setText(0, QString().setNum((long)targetFreeList, 16).prepend("0x"));
    lastItem->setText(1, QString().setNum(0, 16).prepend("0x"));
    targetItem->addChild(lastItem);
}

bool MainWindow::removeExcessItemWhenAllocated(QTreeWidgetItem * item, char * allocateAddr)
{
    int nMemBlockCount = item->childCount();
    for(int i = 0; i < nMemBlockCount; ++i)
    {
        QTreeWidgetItem * memBlockItem = item->child(i);
        if(memBlockItem->text(0) == QString().setNum((long)allocateAddr).prepend("0x"), 16)
        {
            removeMemBlockItemOnGUI(item, i, nMemBlockCount);
            return true;
        }
    }

    assert(nMemBlockCount == 0);
    return false;
}

void MainWindow::removeMemBlockItemOnGUI(QTreeWidgetItem * item,
                                         const int & nTargetIdx,
                                         const int & nItemCount)
{
    QTreeWidgetItem * targetItem = item->takeChild(nTargetIdx);
    if(nTargetIdx == 0)
    {
// TO DO just remove the targetItem
    }
    else if(nTargetIdx == nItemCount - 1)
    {
        QTreeWidgetItem * preMemBlockItem = item->child(nTargetIdx - 1);
        preMemBlockItem->setText(1, QString().setNum(0, 16));
    }
    else
    {
        QTreeWidgetItem * preMemBlockItem = item->child(nTargetIdx - 1);
        QTreeWidgetItem * proMemBlockItem = item->child(nTargetIdx + 1);
        preMemBlockItem->setText(1, proMemBlockItem->text(0));
    }

    delete targetItem;
    targetItem = 0;
}

void MainWindow::updateHeapSize()
{
    ui->lineEdit->setText(QString().setNum(default_allocator::heap_size));
}

void MainWindow::updateMemoryPoolUsage()
{
    int unusedMemory = (int)(default_allocator::end_free - default_allocator::start_free);
    int usedMemory = default_allocator::heap_size - unusedMemory;
    ui->progressBar->setValue(usedMemory * 100 / default_allocator::heap_size);
}

MainWindow::~MainWindow()
{
    delete ui;
}
