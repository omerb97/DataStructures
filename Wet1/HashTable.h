#ifndef WET1_HASHTABLE_H
#define WET1_HASHTABLE_H

#include "ListNode.h"
#include "List.h"

#define STARTING_SIZE 10
#define FILL_RATIO 3

template<class T>
class HashTable
{
private:
    List<T> **table;
    int arraySize;
    int filledNum;

    int HashFunction(int input) const;

    void CheckandReorganize();

public:
    explicit HashTable(int starting_size = STARTING_SIZE);

    ~HashTable();

    void Insert(T *data);

    void Remove(T *data);

    ListNode<T> *Search(T *data) const;
};


template<class T>
HashTable<T>::HashTable(int starting_size) : arraySize(starting_size), filledNum(0)
{
    table = new List<T> *[arraySize]();

    for (int i = 0; i < arraySize; i++)
    {
        table[i] = new List<T>();
    }
}


template<class T>
HashTable<T>::~HashTable()
{
    for (int i = 0; i < arraySize; i++)
    {
        delete table[i];
    }

    delete[] table;
}

template<class T>
int HashTable<T>::HashFunction(int input) const
{
    return (input % this->arraySize);
}

template<class T>
void HashTable<T>::CheckandReorganize()
{
    if (filledNum < arraySize * FILL_RATIO)
    {
        return;
    }
    else
    {
        int oldSize = this->arraySize;
        this->arraySize = this->arraySize * 2;
        List<T> *newTable[this->arraySize];
        for (int i = 0; i < oldSize; i++)
        {
            ListNode<T> *temp = this->table[i]->GetHead();
            while (temp)
            {
                int newHash = HashFunction(
                        temp->GetData()->GetHash());//todo: add a get hash function to class and course
                T *newData(temp->GetData());
                newTable[newHash]->Insert(newData);
                temp = temp->GetNext();
            }
        }
        delete[] this->table;
        this->table = newTable;
    }
}

template<class T>
void HashTable<T>::Insert(T *data)
{
    int hashFuncInput = data->GetHash();
    int hashNum = HashFunction(hashFuncInput);
    List<T> *temp = this->table[hashNum];
    temp->Insert(data);
    this->filledNum++;
    CheckandReorganize();
}

template<class T>
void HashTable<T>::Remove(T *data)
{
    int hashFuncInput = data->GetHash();
    int hashNum = HashFunction(hashFuncInput);
    List<T> *temp = this->table[hashNum];
    temp->Remove(data);
    this->filledNum--;
}

template<class T>
ListNode<T> *HashTable<T>::Search(T *data) const
{
    int hashFuncInput = data->GetHash();
    int hashNum = HashFunction(hashFuncInput);
    List<T>* temp = this->table[hashNum];
    ListNode<T> *wantedNode = temp->Search(data);
    return wantedNode;
}


#endif
