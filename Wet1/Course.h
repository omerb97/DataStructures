#include "Class.h"

#ifndef COURSE_H
#define COURSE_H

class Course
{
private:
    int course_id;
    int num_of_classes;
    Class *classes;

public:
    Course(int course_id, int num_of_classes);

    ~Course();

    int getCourseId();

    int getNumOfClasses();

    Class getClass(int id);

    bool operator<(const Course c) const;

    bool operator==(const Course c) const;
};

#endif
