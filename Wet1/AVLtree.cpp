#include "AVLtree.h"
#include <iostream>



template<class T>
AVLtree<T>::AVLtree(T data, AVLtree *left, AVLtree *right, int height) {
}

template<class T>
T AVLtree<T>::GetData()
{
    return this->data;
}

template<class T>
AVLtree<T>* AVLtree<T>::GetLeft()
{
    return this->left;
}

template<class T>
AVLtree<T>* AVLtree<T>::GetRight()
{
    return this->right;
}

template <class T>
void AVLtree<T>::SetData(T newData)
{
    this->data = newData;
}

template<class T>
void AVLtree<T>::SetLeft(AVLtree<T> *newLeft)
{
    this->left = newLeft;
}

template<class T>
void AVLtree<T>::SetRight(AVLtree<T> *newRight)
{
    this->Right = newRight;
}


template<class T>
int AVLtree<T>::GetHeight(AVLtree<T> *target)
{
    return this->height;
}

template<class T>
int AVLtree<T>::GetDiffrence(AVLtree<T> *target)
{
    int leftHeight = GetHeight(this->GetLeft());
    int rightHeight = GetHeight(this->GetRight());
    int diffrence = leftHeight - rightHeight;
    return diffrence;
}

template<class T>
AVLtree<T>* AVLtree<T>::RR_Rotate(AVLtree<T> *target)
{
    AVLtree<T>* newParent = this->GetRight();
    target->SetRight(newParent->GetLeft());
    newParent->SetLeft(target);
    return newParent;
}

template<class T>
AVLtree<T>* AVLtree<T>::RL_Rotate(AVLtree<T> *target)
{
    AVLtree<T>* node = (target->GetRight());
    target->SetRight(LL_Rotate(node));
    AVLtree<T>* newParent = (RR_Rotate(target));
    return newParent;
}

template<class T>
AVLtree<T>* AVLtree<T>::LR_Rotate(AVLtree<T> *target)
{
    AVLtree<T>* node = (target->GetLeft());
    target->SetRight(RR_Rotate(node));
    AVLtree<T>* newParent = (LL_Rotate(target));
    return newParent;
}

template<class T>
AVLtree<T>* AVLtree<T>::LL_Rotate(AVLtree<T> *target)
{
    AVLtree<T>* newParent = this->GetLeft();
    target->SetLeft(newParent->GetRight());
    newParent->SetRight(target);
    return newParent;
}

template<class T>
AVLtree<T>* AVLtree<T>::BalanceTree(AVLtree<T> *target)
{
    int bf = GetDiffrence(target);
    AVLtree* leftSon = target->GetLeft();
    AVLtree* rightSon = target->GetRight();
    if (bf >= 2){
        if (GetDiffrence(leftSon) == -1){
            target = LR_Rotate(target);
        } else{
            target = LL_Rotate(target);
        }
    }
    if (bf <= -2){
        if(GetDiffrence(rightSon) == 1){
            target = RL_Rotate(target);
        } else{
            target = RR_Rotate(target);
        }
    }
    return target;
}

template<class T>
AVLtree<T>* AVLtree<T>::Insert(AVLtree<T> *parent, T insertData)
{
    if (parent == NULL){ //this means we are trying to start a new AVL tree
        AVLtree<T>(insertData, NULL, NULL);
    }
    T parentData = parent->GetData();
    if (insertData < parentData){
        parent->SetLeft(Insert(parent->GetLeft(), insertData));
    }
    if (insertData > parentData){
        parent->SetRight(Insert(parent->GetRight(), insertData));
    }
    *parent = BalanceTree(parent);
    return parent;
}

template<class T>
AVLtree<T>* AVLtree<T>::Inorder(AVLtree<T> *root)
{
    if (root == NULL){
        return;
    }
    inorder(root->GetLeft());
    std::cout << this->GetData();
    inorder(root->GetRight());
}

template<class T>
AVLtree<T>* AVLtree<T>::Search(AVLtree<T>* root, T wantedData)
{
    if (root == NULL){ // if at the end it will return NULL it means it hasn't found it
        return;
    }
    if (root->GetData() == wantedData){
        return root;
    }
    if (root->GetData() > wantedData){
        return Search(root->GetLeft());
    }
    if (root->GetData() < wantedData){
        return Search(root->GetRight());
    }
}

template<class T>
AVLtree<T> *AVLtree<T>::Search(AVLtree *root, int wantedData) {
    if (root == NULL){ // if at the end it will return NULL it means it hasn't found it
        return NULL;
    }
    if (root->GetData() == wantedData){
        return root;
    }
    if (root->GetData() > wantedData){
        return Search(root->GetLeft());
    }
    if (root->GetData() < wantedData){
        return Search(root->GetRight());
    }
}

template<class T>
bool AVLtree<T>::IsExist(int wantedData) {
    if (this->Search(this, wantedData) == NULL){
        return false;
    }
    else{
        return true;
    }
}


