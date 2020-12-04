#include "CoursesManager.h"

CoursesManager* CoursesManager::Init()
{
    //todo: create a new one with all the neccery one. blank
    CoursesManager reVal;
    return *reVal;
}

void CoursesManager::addCourse( int courseID, int numOfClasses)
{
    //todo: add allocation error
    if (this == nullptr || courseID <=0 || numOfClasses <= 0){
        throw InvalidInputs();
    }

    auto newCourse = new Course(courseID, numOfClasses);
    if (this->courseTree.Search(&courseTree, *newCourse ) != nullptr || this->courseTree.Search(&courseTree, *newCourse ) != nullptr){
        throw TreeValueExists();
    }
    //will only reach here if everything worked
    this->courseTree.Insert(&courseTree, *newCourse);
}

void CoursesManager::removeCourse(int CourseID)
{
    if (this == nullptr || CourseID <= 0){
        throw InvalidInputs();
    }

    auto searchCourse = new Course(CourseID, 0);
    if (this->courseTree.Search(&courseTree, *searchCourse) == NULL){
        TreeValueNoExist();
    }

    //remove course from the courses tree
    //todo: make sure remove is added from courses tree
    //todo: remove from time tree

}

void CoursesManager::watchTime(int courseID, int classID, int time)
{
    if (this == nullptr || courseID <= 0 || classID <=0 || time <=0 ){
        throw InvalidInputs();
    }
    Course wantedCourse = (this->courseTree.Search(&courseTree, courseID))->GetData();

    if (!this->courseTree.IsExist(courseID)){
        throw TreeValueNoExist();
    }
    if (classID > wantedCourse.getNumOfClasses()){
        throw InvalidInputs();
    }
    //todo: classID has to be above 0 so it is not 0 to (n-1) as we are used to
    Class wantedClass = wantedCourse.getClass(classID);
    //todo: the function wnated class returns by value? so maybe if we change some value here it wont change it?
    wantedClass.addTime(time);

    //todo: add time add if it is watched and need to add time to avl tree
}

void CoursesManager::timeViewed(int courseID, int classID, int *timeviewed)
{
    if (this == nullptr || courseID <= 0 || classID <= 0){
        throw InvalidInputs();
    }
    if (!this->courseTree.IsExist(courseID)){
        throw TreeValueNoExist();
    }
    Course wantedCourse = this->courseTree.Search(&courseTree, courseID)->GetData();

    if (classID > wantedCourse.getNumOfClasses()){
        throw InvalidInputs();
    }

    Class wantedClass = wantedCourse.getClass(classID);
    *timeviewed = wantedClass.getTime();

}
