
#ifndef AVL_AVLTREE_H
#define AVL_AVLTREE_H

#include <iostream>

template<class T>
struct Node
{
    T data;
    Node *left;
    Node *right;
    Node *parent;
    int balance_factor;
};

template<class T>
class AVLtree
{
private:
    Node<T> *root;

    void createNode(Node<T> *node, T data);

    void inOrderHelper(Node<T> *node);

    void preOrderHelper(Node<T> *node);

    Node<T> *searchHelper(Node<T> *node, T data);

    Node<T> *deleteNodeHelper(Node<T> *node, T data);

    Node<T> *minimumNode(Node<T> *node);

    Node<T> *maximumNode(Node<T> *node);

    void rebalanceAfterInsert(Node<T> *node);

    void rebalanceAfterDelete(Node<T> *node);

    void balanceTree(Node<T> *node);

    void updateBalance(Node<T> *node);

    void leftRotate(Node<T> *node);

    void rightRotate(Node<T> *node);

    void clearHelper(Node<T> *node);

    int getBalanceFactor(Node<T> *node);

    int getHeight(Node<T> *node);

    int max(int x, int y);

public:
    AVLtree(); //c'tor
    AVLtree(const AVLtree &node); //copy c'tor
    ~AVLtree(); //d'tor

    void insert(T insertData);

    Node<T> *deleteNode(T data);

    void inOrder();

    void preOrder();

    Node<T> *search(T wantedData);

    T *GetData(Node<T>* node)
};

template<class T>
AVLtree<T>::AVLtree()
{
    root = nullptr;
}


template<class T>
AVLtree<T>::AVLtree(const AVLtree &node) : root(node.root)
{

}

template<class T>
AVLtree<T>::~AVLtree()
{
    clearHelper(root);
}

template<class T>
void AVLtree<T>::balanceTree(Node<T> *node)
{
    if (node->balance_factor < -1 || node->balance_factor > 1)
    {
        rebalanceAfterInsert(node);
        return;
    }

    if (node->parent != nullptr)
    {
        if (node == node->parent->left)
        {
            node->parent->balance_factor -= 1;
        }

        if (node == node->parent->right)
        {
            node->parent->balance_factor += 1;
        }

        if (node->parent->balance_factor != 0)
        {
            balanceTree(node->parent);
        }
    }
}

template<class T>
void AVLtree<T>::insert(T insertData)
{
    Node<T> *node = new Node<T>;
    createNode(node, insertData);
    Node<T> *y = nullptr;
    Node<T> *x = this->root;

    while (x != nullptr)
    {
        y = x;
        if (node->data < x->data)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    // y is parent of x
    node->parent = y;
    if (y == nullptr)
    {
        root = node;
    }
    else if (node->data < y->data)
    {
        y->left = node;
    }
    else
    {
        y->right = node;
    }

    balanceTree(node);
}

template<class T>
void AVLtree<T>::inOrder()
{
    inOrderHelper(root);
}

template<class T>
void AVLtree<T>::createNode(Node<T> *node, T data)
{
    node->data = data;
    node->parent = nullptr;
    node->left = nullptr;
    node->right = nullptr;
    node->balance_factor = 0;
}

template<class T>
void AVLtree<T>::inOrderHelper(Node<T> *node)
{
    if (node == NULL)
    {
        return;
    }
    inOrderHelper(node->left);
    std::cout << node->data << " ";
    inOrderHelper(node->right);
}

template<class T>
void AVLtree<T>::leftRotate(Node<T> *node)
{
    Node<T> *temp = node->right;
    node->right = temp->left;
    if (temp->left != nullptr)
    {
        temp->left->parent = node;
    }
    temp->parent = node->parent;
    if (node->parent == nullptr)
    {
        this->root = temp;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = temp;
    }
    else
    {
        node->parent->right = temp;
    }
    temp->left = node;
    node->parent = temp;

    // update the balance factor
    if (temp->balance_factor > 0)
    {
        node->balance_factor = node->balance_factor - 1 - temp->balance_factor;
    }
    else
    {
        node->balance_factor = node->balance_factor - 1;
    }

    if (node->balance_factor < 0)
    {
        temp->balance_factor = temp->balance_factor - 1 + node->balance_factor;
    }
    else
    {
        temp->balance_factor = temp->balance_factor - 1;
    }
}

template<class T>
void AVLtree<T>::rightRotate(Node<T> *node)
{
    Node<T> *temp = node->left;
    node->left = temp->right;

    if (temp->right != nullptr)
    {
        temp->right->parent = node;
    }
    temp->parent = node->parent;
    if (node->parent == nullptr)
    {
        this->root = temp;
    }
    else if (node == node->parent->right)
    {
        node->parent->right = temp;
    }
    else
    {
        node->parent->left = temp;
    }
    temp->right = node;
    node->parent = temp;

    // update the balance factor
    if (temp->balance_factor < 0)
    {
        node->balance_factor = node->balance_factor + 1 - temp->balance_factor;
    }
    else
    {
        node->balance_factor = node->balance_factor + 1;
    }

    if (node->balance_factor > 0)
    {
        temp->balance_factor = temp->balance_factor + 1 + node->balance_factor;
    }
    else
    {
        temp->balance_factor = temp->balance_factor + 1;
    }
}

template<class T>
void AVLtree<T>::rebalanceAfterInsert(Node<T> *node)
{
    if (node->balance_factor > 0)
    {
        if (node->right->balance_factor < 0)
        {
            rightRotate(node->right);
            leftRotate(node);
        }
        else
        {
            leftRotate(node);
        }
    }
    else if (node->balance_factor < 0)
    {
        if (node->left->balance_factor > 0)
        {
            leftRotate(node->left);
            rightRotate(node);
        }
        else
        {
            rightRotate(node);
        }
    }
}

template<class T>
Node<T> *AVLtree<T>::search(T wantedData)
{
    return searchHelper(root, wantedData);
}

template<class T>
Node<T> *AVLtree<T>::searchHelper(Node<T> *node, T data)
{
    if (node == nullptr || data == node->data)
    {
        return node;
    }

    if (data < node->data)
    {
        return searchTreeHelper(node->left, data);
    }
    return searchTreeHelper(node->right, data);
}

template<class T>
Node<T> *AVLtree<T>::deleteNodeHelper(Node<T> *node, T data) //TO DO///////////////////////////////////////////////
{
    if (node == nullptr)
    {
        return node;
    }
    else if (data < node->data)
    {
        node->left = deleteNodeHelper(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = deleteNodeHelper(node->right, data);
    }
    else
    {
        // the value has been found

        //node is a leaf
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            node = nullptr;
        }

            //node has only one son
        else if (node->left == nullptr)
        {
            Node<T> *temp = node;
            node = node->right;
            node->parent = temp->parent;
            if (node->parent->right == temp)
            {
                node->parent->right = node;
            }
            else
            {
                node->parent->left = node;
            }
            delete temp;
        }
        else if (node->right == nullptr)
        {
            Node<T> *temp = node;
            node = node->left;
            node->parent = temp->parent;
            if (node->parent->right == temp)
            {
                node->parent->right = node;
            }
            else
            {
                node->parent->left = node;
            }
            delete temp;
        }

            //node has two sons
        else
        {
            Node<T> *temp = minimumNode(node->right);
            node->data = temp->data;
            node->right = deleteNodeHelper(node->right, temp->data);
        }
    }

    updateBalance(node);

    return node;
}

template<class T>
Node<T> *AVLtree<T>::deleteNode(T data)
{
    Node<T> *deletedNode = deleteNodeHelper(root, data);
    return deletedNode;
}

template<class T>
Node<T> *AVLtree<T>::minimumNode(Node<T> *node)
{
    Node<T> *current = node;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

template<class T>
Node<T> *AVLtree<T>::maximumNode(Node<T> *node)
{
    Node<T> *current = node;
    while (current->right != nullptr)
    {
        current = current->right;
    }
    return current;
}

template<class T>
void AVLtree<T>::clearHelper(Node<T> *node)
{
    if (node != NULL)
    {
        clearHelper(node->left);   // Recursively clear the left sub-tree
        clearHelper(node->right);   // Recursively clear the right sub-tree
        delete node;         // Delete this node
    }
}

template<class T>
int AVLtree<T>::max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

template<class T>
int AVLtree<T>::getHeight(Node<T> *node)
{
    if (!node)
    {
        return -1;
    }
    return max(getHeight(node->left), getHeight(node->left)) + 1;

}

template<class T>
int AVLtree<T>::getBalanceFactor(Node<T> *node)
{
    return getHeight(node->left) - getHeight(node->right);
}

template<class T>
void AVLtree<T>::preOrderHelper(Node<T> *node)
{
    if (node == NULL)
    {
        return;
    }
    std::cout << node->data << " ";
    preOrderHelper(node->left);
    preOrderHelper(node->right);
}

template<class T>
void AVLtree<T>::preOrder()
{
    preOrderHelper(root);
}

template<class T>
void AVLtree<T>::updateBalance(Node<T> *node)
{
    if (!node)
    {
        return;
    }

    node->balance_factor = getBalanceFactor(node);
    if (node->balance_factor < -1 || node->balance_factor > 1)
    {
        rebalanceAfterDelete(node);
        return;
    }
    updateBalance(node->parent);
}

template<class T>
void AVLtree<T>::rebalanceAfterDelete(Node<T> *node)
{
    //LL
    if (node->balance_factor > 1 && node->left->balance_factor >= 0)
    {
        rightRotate(node);
    }
        //LR
    else if (node->balance_factor > 1 && node->left->balance_factor < 0)
    {
        leftRotate(node->left);
        rightRotate(node);
    }
        // Right Right Case
    else if (node->balance_factor < -1 && node->right->balance_factor <= 0)
    {
        leftRotate(node);
    }
        // Right Left Case
    else if (node->balance_factor < -1 && node->right->balance_factor > 0)
    {
        rightRotate(node->right);
        leftRotate(node);
    }

}

template<class T>
T *AVLtree<T>::GetData(Node<T> *node) {
    return node->data;
}

#endif
