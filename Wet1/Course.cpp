#include "Course.h"

Course::Course(int course_id, int num_of_classes)
{
    this->course_id = course_id;
    this->num_of_classes = num_of_classes;
    this->classes = new Class[num_of_classes];

    for (int i = 0; i < num_of_classes; i++) {
        classes[i] = Class(i, 0);
    }
}

Course::~Course()
{
    delete[] classes;
}

Class Course::getClass(int id)
{
    return classes[id];
}

int Course::getCourseId()
{
    return course_id;
}

int Course::getNumOfClasses()
{
    return num_of_classes;
}