#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "HashTable.h"
#include "Course.h"
#include "Class.h"
#include "library2.h"
#include "CoursesManager.h"

int main() {
    HashTable<Course> initTry;
    Course tryCourse(2343,2);
    initTry.Insert(tryCourse);
    int o= 5;
    return 0;
}
