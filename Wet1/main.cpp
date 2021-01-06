#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "HashTable.h"
#include "Course.h"
#include "Class.h"
int main() {
    HashTable<Course> initTry;
    Course tryCourse(2343,2);
    initTry.Insert(tryCourse);
    int o= 5;
    return 0;
}
