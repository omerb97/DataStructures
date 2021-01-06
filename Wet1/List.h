#ifndef WET1_LIST_H
#define WET1_LIST_H

#include "ListNode.h"

template <class T>
class List
{
private:
    ListNode<T>* head;
    int length;

public:
    explicit List();
    ~List() = default;
    ListNode<T>* GetHead();
    int GetLength();
    void Insert(T data);
    void Remove(T data);
    ListNode<T>* Search(T data);
};

template<class T>
List<T>::List() : head(nullptr), length(0){}



//todo: dont really know what to do with all the ctor dto etc...

template<class T>
ListNode<T>* List<T>::GetHead()
{
    return this->head;
}

template<class T>
int List<T>::GetLength()
{
    return this->length;
}

template<class T>
void List<T>::Insert(T data)
{
    ListNode<T> newNode = ListNode<T>(data, nullptr);
    ListNode<T> temp = *this->head;
    while (temp.GetNext())
    {
        temp = *(temp.GetNext());
    }
    temp.SetNext(&newNode);
    this->length++;
}


template<class T>
ListNode<T>* List<T>::Search(T data)
{
    ListNode<T> temp = *this->head;
    while (temp.GetData() != data && temp != nullptr)
    {
        temp = temp.GetNext();
    }
    temp = nullptr;
    if (temp == nullptr)
    {
        return NULL;
    }
    else
    {
        return temp;
    }
}

template<class T>
void List<T>::Remove(T data)
{
    if (Search(data) == NULL)
    {
        return;
    }
    if (this->head->GetData() == data)//if its the first node that we are deleting
    {
        ListNode<T>* deleteNode = *this->head;
        if(this->head->GetNext())
        {
            ListNode<T> newHead = this->head->GetNext();
            this.head = newHead;
            delete deleteNode;
        }
        else
        {
            this.head = nullptr;
            delete deleteNode;
        }
    }
    else
    {
        int position = 2;
        ListNode<T> *previous = this->head;
        ListNode<T> *current = this->head->GetNext();
        while (current->GetData() != data && current != NULL)
        {
            previous = current; // need to implement and operator =
            current = current->GetNext();
            position++;
        }
        previous->SetNext(current->GetNext());
        delete current;
    }
    this->length--;
}



#endif
