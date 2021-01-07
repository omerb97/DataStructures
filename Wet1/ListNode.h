#ifndef WET1_LISTNODE_H
#define WET1_LISTNODE_H

template <class T>
class ListNode
{
private:
    T* Data;
    ListNode* next;
public:
    ListNode() = default; //c'tor
    ListNode(T* data, ListNode<T> *next); //c'tor
    ~ListNode() = default;
    ListNode& operator=(ListNode<T> const& other);
    T* GetData();
    ListNode* GetNext();
    void SetNext(ListNode<T>* nextNode);

    void SetData(T data);

};

template<class T>
ListNode<T>::ListNode(T* data, ListNode<T> *next)
{
    this->Data = data;
    this->next = next;
}

//todo: dont really know what to do with all the cto dtor etc...

template<class T>
T* ListNode<T>::GetData()
{
    return this->Data;
}

template<class T>
ListNode<T>* ListNode<T>::GetNext()
{
    return this->next;
}

template<class T>
void ListNode<T>::SetData(T data)
{
    this->Data = data;
}

template<class T>
void ListNode<T>::SetNext(ListNode<T>* nextNode)
{
    this->next = nextNode;
}

template<class T>
ListNode<T>& ListNode<T>::operator=(ListNode<T>const& other)
{
    this->Data = other.Data;
    this->next = other.next;
}


#endif
