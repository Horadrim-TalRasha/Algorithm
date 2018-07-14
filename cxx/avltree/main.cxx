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
        void setRightChild(AVLTreeNode * node);
        void setLeftChild(AVLTreeNode * node);
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
    void InorderTraversal();
    void PreOrderTraversal();

private:
    int __height(const AVLTreeNode * node);
    int __diff(const AVLTreeNode * node);
    void __doInsertNode(AVLTreeNode * node, const int & nodeValue);
    AVLTreeNode * __searchBalancePointer(const int & nodeValue);
    void __InorderTraversal(AVLTreeNode * node);
    void __PreOrderTraversal(AVLTreeNode * node);

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
        AVLTree::AVLTreeNode * balanceNode = __searchBalancePointer(nodeValue);
        __doInsertNode(balanceNode, nodeValue);
        return balanceNode;   
    }
}

void
AVLTree::InorderTraversal()
{
    __InorderTraversal(m_rootNode);
}

void
AVLTree::PreOrderTraversal()
{
    __PreOrderTraversal(m_rootNode);
}

void
AVLTree::__InorderTraversal(AVLTree::AVLTreeNode * node)
{
    if(node == NULL)
    {
        return;
    }

    __InorderTraversal(node->leftChild());
    printf("%d\n", node->nodeValue());
    __InorderTraversal(node->rightChild());
}

void
AVLTree::__PreOrderTraversal(AVLTree::AVLTreeNode * node)
{
    if(node == NULL)
    {
        return;
    }

    printf("%d\n", node->nodeValue());
    __PreOrderTraversal(node->leftChild());
    __PreOrderTraversal(node->rightChild());
}

void
AVLTree::__doInsertNode(AVLTree::AVLTreeNode * balanceNode, const int & nodeValue)
{
    AVLTree::AVLTreeNode * startNode = balanceNode;
    while(startNode != NULL)
    {
        if(nodeValue >= startNode->nodeValue())
        {
            if(startNode->rightChild() != NULL)
            {
                startNode = startNode->rightChild();
                continue;
            }
            else
            {
                AVLTree::AVLTreeNode * newNode = new AVLTree::AVLTreeNode(nodeValue);
                startNode->setRightChild(newNode);
                return;
            }
        }
        else
        {
            if(startNode->leftChild() != NULL)
            {
                startNode = startNode->leftChild();
                continue;
            }
            else
            {
                AVLTree::AVLTreeNode * newNode = new AVLTree::AVLTreeNode(nodeValue);
                startNode->setLeftChild(newNode);
                return;
            }
        }

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
	AVLTree::AVLTreeNode * startLeftNode = startNode->leftChild();
    AVLTree::AVLTreeNode * startRightNode = startNode->rightChild();
	while(startLeftNode != NULL && startRightNode != NULL &&
		startLeftNode->hasChild() && startRightNode->hasChild())
    {
        if(nodeValue >= startNode->nodeValue())
		{
            startNode = startRightNode;
			startLeftNode = startNode->leftChild();
			startRightNode = startNode->rightChild();
		}
		else if(nodeValue < startNode->nodeValue())
		{
            startNode = startLeftNode;
			startLeftNode = startNode->leftChild();
			startRightNode = startNode->rightChild();
		}
    }

	return startNode;
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
AVLTree::AVLTreeNode::hasChild()
{
    return (m_leftNode != NULL) || (m_rightNode != NULL);
}

void
AVLTree::AVLTreeNode::setRightChild(AVLTree::AVLTreeNode * node)
{
    m_rightNode = node;
}

void
AVLTree::AVLTreeNode::setLeftChild(AVLTree::AVLTreeNode * node)
{
    m_leftNode = node;
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
    AVLTree testTree;

    testTree.Insert(2);
    testTree.Insert(1);
    testTree.Insert(3);
    testTree.Insert(6);
    testTree.Insert(5);
    printf("Pre order:\n");
    testTree.PreOrderTraversal();

    printf("In order:\n");
    testTree.InorderTraversal();
    return 0;
}
