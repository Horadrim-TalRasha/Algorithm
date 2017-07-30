#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <assert.h>

#include "ui_mainwindow.h"
#include "default_alloc.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private:
    Ui::MainWindow *ui;

    typedef __default_alloc_template<false, 0> default_allocator;

    QMap<char *, size_t> m_allocatedMemBlocks;

    void fillMemPoolInfoWidget();
    void updateMemPoolInfoWidget(const size_t & index, char * allocatedAddr);
    bool removeExcessItemWhenAllocated(QTreeWidgetItem * item, char * allocateAddr);
    void removeMemBlockItemOnGUI(QTreeWidgetItem * item, const int & nTargetIdx, const int & nItemCount);
    void updateHeapSize();
    void updateMemoryPoolUsage();

private slots:
    void memAllocSlot();
};

#endif // MAINWINDOW_H
