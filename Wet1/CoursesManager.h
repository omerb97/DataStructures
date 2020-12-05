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
    AVLtree<Course> courseTree;
    AVLtree<Class> timeTree;
public:
    CoursesManager(); //c'tor
    ~CoursesManager();
    CoursesManager* Init();
    void addCourse (int courseID, int numOfClasses);
    void removeCourse (int CourseID);
    void watchClass (int courseID, int classID, int time);
    void timeViewed (int courseID, int classID, int *timeviewed);
    void Quit();
};
#endif
