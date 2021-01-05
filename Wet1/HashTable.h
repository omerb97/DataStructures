#ifndef WET1_HASHTABLE_H
#define WET1_HASHTABLE_H

#include "ListNode.h"
#include "List.h"

#define STARTING_SIZE 500

template <class T>
class HashTable
{
private:
    List<T>[] table;
    int arraySize;
    int filledNum;

public:
    explicit HashTable();
    ~HashTable();
    HashTable(const HashTable<T>& hash)
    void Insert (T )
};

//todo dont really know what to do with all the ctor dto etc...

#endif
