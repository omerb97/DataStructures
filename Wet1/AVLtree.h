
#ifndef AVL_AVLTREE_H
#define AVL_AVLTREE_H
//test

#include <iostream>

template <class T>
class AVLtree
{
private:
    T* data;
    AVLtree *left;
    AVLtree *right;
    int height;
public:
    explicit AVLtree(T data, AVLtree *left, AVLtree *right, int height); //c'tor
    ~AVLtree(); //d'tor
    AVLtree(const AVLtree& node); //copy c'tor
    T GetData (); //return data of current node
    AVLtree* GetLeft (); // return ptr to left son
    AVLtree* GetRight (); // return ptr to right son
    void SetData(T newData);
    void SetLeft(AVLtree<T>* newLeft);
    void SetRight(AVLtree<T>* newRight);
    int GetHeight (AVLtree* target); //return height of node
    int GetDiffrence (AVLtree* target); // return height diff of sons
    AVLtree* RR_Rotate(AVLtree* target);
    AVLtree* RL_Rotate(AVLtree* target);
    AVLtree* LR_Rotate(AVLtree* target);
    AVLtree* LL_Rotate(AVLtree* target);
    AVLtree* BalanceTree (AVLtree* target);
    AVLtree* Insert (AVLtree* parent, T insertData);
    AVLtree* Inorder (AVLtree* root);
    AVLtree* Search (AVLtree* root, T wantedData);
};


#endif
