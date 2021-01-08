#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "HashTable.h"
#include "Course.h"
#include "Class.h"
#include "library2.h"
#include "CoursesManager.h"

int main() {
    HashTable<Course> initTry = HashTable<Course>();
    Course tryCourse(10);
    initTry.Insert(&tryCourse);

    if(initTry.Search(&tryCourse))
    {
        std::cout << "success"<< std::endl;
    }

    initTry.Remove(&tryCourse);

    if(!initTry.Search(&tryCourse))
    {
        std::cout << "success" << std::endl;
    }

    int o= 5;
    return 0;
}
