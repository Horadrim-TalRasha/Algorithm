#include <stdio.h>




class AVLTree
{
private:
    class AVLTreeNode
    {
    public:
        AVLTreeNode();
        AVLTreeNode(const int & nodeValue);
        ~AVLTreeNode();

    private:
        int m_nodeValue;

        AVLTreeNode * m_leftNode;
        AVLTreeNode * m_rightNode;
    };

public:
    AVLTree();
    ~AVLTree();

    AVLTreeNode * Insert(const int & nodeValue);

private:
    int __height(const AVLTreeNode * node);
    int __diff(const AVLTreeNode * node);
    AVLTreeNode * __searchInsertPointer(const int & nodeValue);

    AVLTreeNode * m_rootNode;
};


AVLTree::AVLTree() :
m_rootNode(NULL)
{


}

AVLTree::~AVLTree()
{


}

AVLTree::AVLTreeNode *
AVLTree::Insert(const int & nodeValue)
{
    if(m_rootNode == NULL)
    {
        m_rootNode = new AVLTree::AVLTreeNode(nodeValue);
        return m_rootNode;
    }
    else
    {

   
    }
}

AVLTree::AVLTreeNode *
AVLTree::__searchInsertPointer(const int & nodeValue)
{



}

AVLTree::AVLTreeNode::AVLTreeNode() :
m_nodeValue(0),
m_leftNode(NULL),
m_rightNode(NULL)
{


}

AVLTree::AVLTreeNode::AVLTreeNode(const int & nodeValue) :
m_nodeValue(nodeValue),
m_leftNode(NULL),
m_rightNode(NULL)
{


}

AVLTree::AVLTreeNode::~AVLTreeNode()
{


}


int main(int argc, char** argv)
{

    return 0;
}
