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
	    bool isLeafNode();
		bool hasLeftChild();
		bool hasRightChild();
		bool hasChild();
		AVLTreeNode * rightChild();
		AVLTreeNode * leftChild();
        const int & nodeValue();

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
    AVLTreeNode * __searchBalancePointer(const int & nodeValue);

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
        AVLTree::AVLTreeNode * insertParentNode = __searchBalancePointer(nodeValue);
        
   
    }
}

AVLTree::AVLTreeNode *
AVLTree::__searchBalancePointer(const int & nodeValue)
{
	if(m_rootNode->isLeafNode())
    {
        return m_rootNode;
    }
    AVLTree::AVLTreeNode * startNode = m_rootNode;
	while(startNode != NULL)
    {
        AVLTree::AVLTreeNode * startLeftNode = startNode->leftChild();
    	AVLTree::AVLTreeNode * startRightNode = startNode->rightChild();
    	if(startLeftNode == NULL || startRightNode == NULL)
        {
            return startNode;
        }
        else
		{
            
		}
    }
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

bool
AVLTree::AVLTreeNode::isLeafNode()
{
    return (m_leftNode == NULL) && (m_rightNode == NULL);
}

bool
AVLTree::AVLTreeNode::hasLeftChild()
{
    return (m_leftNode != NULL) && (m_rightNode == NULL);
}

bool
AVLTree::AVLTreeNode::hasRightChild()
{
    return (m_leftNode == NULL) && (m_rightNode != NULL);
}

bool
AVLTree::AVLTreeNode::hasRightChild()
{
    return (m_leftNode != NULL) || (m_rightNode != NULL);
}

AVLTree::AVLTreeNode *
AVLTree::AVLTreeNode::rightChild()
{
    return m_rightNode;
}

AVLTree::AVLTreeNode *
AVLTree::AVLTreeNode::leftChild()
{
    return m_leftNode;
}

const int &
AVLTree::AVLTreeNode::nodeValue()
{
    return m_nodeValue;
}

int main(int argc, char** argv)
{

    return 0;
}
