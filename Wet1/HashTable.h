#ifndef WET1_HASHTABLE_H
#define WET1_HASHTABLE_H

#include "ListNode.h"
#include "List.h"

#define STARTING_SIZE 500
#define FILL_RATIO 3

template <class T>
class HashTable
{
private:
    List<T>* table; //todo maybe it needs to be an array if pointers to lists and not an array of lists
    int arraySize;
    int filledNum;

    int HashFunction(int input);
    void CheckandReorganize();
public:
    explicit HashTable(int starting_size_ = STARTING_SIZE);
    ~HashTable();
    void Insert (T data);
    void Remove (T data);
    ListNode<T>* Search (T data);
};


template<class T>
HashTable<T>::HashTable(int starting_size_) : arraySize(starting_size_), filledNum(0)
{
    table = new List<T>[arraySize];
}


template<class T>
HashTable<T>::~HashTable()
{
//    for (int i = 0; i < arraySize; i++)
//    {
//        delete table[i];
//    }

    delete[] table;
}

template <class T>
int HashTable<T>::HashFunction(int input)
{
    return (input % this->arraySize);
}

template <class T>
void HashTable<T>::CheckandReorganize()
{
    if (filledNum < arraySize*FILL_RATIO)
    {
        return;
    }
    else
    {
        int oldSize = this->arraySize;
        this->arraySize = this->arraySize*2;
        List<T> newTable[this->arraySize];
        for (int i= 0; i < oldSize; i++)
        {
            ListNode<T> temp = *this->table[i].GetHead();
            while (table[i] != nullptr)
            {
                int newHash = HashFunction(temp.GetData().GetHash());//todo: add a get hash function to class and course
                T newData = temp.GetData();
                newTable[i].Insert(newData);
            }
        }
        delete[] this->table;
        this->table = newTable;
    }
}

template <class T>
void HashTable<T>::Insert(T data)
{
    int hashFuncInput = data.GetHash(); //todo: make getHash function for course and class
    int hashNum = hashFuncInput%this->arraySize;
    List<T> temp = this->table[hashNum];
    temp.Insert(data);
    this->filledNum++;
    CheckandReorganize();
}

template <class T>
void HashTable<T>::Remove(T data)
{
    int hashFuncInput = data.GetHash();
    int hashNum = hashFuncInput%this->arraySize;
    List<T> temp = this->table[hashNum];
    temp.Remove(data);
    this->filledNum--;
}

template <class T>
ListNode<T>* HashTable<T>::Search(T data)
{
    int hashFuncInput = data.GetHash();
    int hashNum = hashFuncInput%this->arraySize;
    List<T> temp = this->table[hashNum];
    ListNode<T> wantedNode = temp.Search(data);
    return wantedNode;
}



#endif
