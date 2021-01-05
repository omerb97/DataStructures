#ifndef WET1_LISTNODE_H
#define WET1_LISTNODE_H

template <class T>
class ListNode
{
private:
    T* Data;
    ListNode* next;
public:
    explicit ListNode(T data, ListNode *next); //c'tor
    ~ListNode();
    ListNode(const ListNode<T>& node);
    T GetData();
    ListNode* GetNext();
    void SetNext(const ListNode* nextNode);
    void SetData(const T data);

};

//todo: dont really know what to do with all the cto dtor etc...

template<class T>
T ListNode<T>::GetData()
{
    return this->Data;
}

template<class T>
ListNode<T>* ListNode<T>::GetNext()
{
    return this->next;
}

template<class T>
void ListNode<T>::SetData(const T data)
{
    this->Data = data;
}

template<class T>
void ListNode<T>::SetNext(const ListNode* nextNode)
{
    this->next = nextNode;
}
#endif
