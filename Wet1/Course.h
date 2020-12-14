#include "Class.h"

#ifndef COURSE_H
#define COURSE_H

class Course
{
private:
    int course_id;
    int num_of_classes;
    Class* classes;

public:
    Course() = default;

    Course(Course& course);

    Course(int course_id, int num_of_classes);

    Course& operator=(Course& other);

    ~Course();

    int getCourseId();

    int getNumOfClasses();

    Class getClass(int id);

    void addTime(int class_id, int time);

    bool operator<(const Course c) const;

    bool operator>(const Course c) const;

    bool operator==(const Course c) const;
};

#endif
