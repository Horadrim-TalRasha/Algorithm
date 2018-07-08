#include <stdio.h>




class AVLTree
{
public:
    AVLTree();
    ~AVLTree();

private:
    class AVLTreeNode
    {
    public:
        AVLTreeNode();
        ~AVLTreeNode();

    private:
        int m_nodeValue;

        AVLTreeNode * m_leftNode;
        AVLTreeNode * m_rightNode;
    };


    int __height(const AVLTreeNode * node);
    int __diff(cont AVLTreeNode * node);

    AVLTreeNode * m_rootNode;
};


AVLTree::AVLTree() :
m_rootNode(NULL)
{


}

AVLTree::~AVLTree()
{


}

AVLTree::AVLTreeNode::AVLTreeNode() :
m_nodeValue(0),
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
