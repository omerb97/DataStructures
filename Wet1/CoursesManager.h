#ifndef WET1_COURSESMANAGER_H
#define WET1_COURSESMANAGER_H

#include <iostream>
#include "AVLtree.h"
#include "Class.h"
#include "Course.h"
#include "Exceptions.h"

class CoursesManager
{
private:
    //todo: add time tree two way avl
    AVLtree<Course> courseTree;
public:
    explicit CoursesManager(); //c'tor
    ~CoursesManager();
    CoursesManager* Init();
    void addCourse (int courseID, int numOfClasses);
    void removeCourse (int CourseID);
    void watchTime (int courseID, int classID, int time);
    void timeViewed (int courseID, int classID, int *timeviewed);
    void Quit();
};
#endif
