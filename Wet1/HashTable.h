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
    List<T> table[];
    int arraySize;
    int filledNum;

    int HashFunction(int input);
    void CheckandReorganize();
public:
    explicit HashTable();
    ~HashTable();
    HashTable(const HashTable<T>& hash);
    void Insert (T data);
    void Remove (T data);
    ListNode<T>* Search (T data);
};

//todo dont really know what to do with all the ctor dto etc...

template <class T>
int HashTable<T>::HashFunction(int input)
{
    return (input%this->arraySize);
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
        for (int = 0; i < oldSize; i++)
        {
            ListNode<T> temp = this->table[i].GetHead();
            while (table[i] != nullptr)
            {
                int newHash = HashFunction(temp.GetData().GetHash());//todo: add a get hash function to class and course
                T newData = temp.GetData();
                new newTable[i].Insert(newData);
            }
        }
        delete[] this->table;
        this->table = newTable;
    }
}

template <class T>
void HashTable<T>::Insert(T data)
{
    int hashFuncInput = data.GetHash();
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
