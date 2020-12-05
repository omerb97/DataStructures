#include "CoursesManager.h"


void CoursesManager::addCourse( int courseID, int numOfClasses)
{
    //todo: add allocation error
    if (courseID <=0 || numOfClasses <= 0){
        throw InvalidInputs();
    }

    auto newCourse = new Course(courseID, numOfClasses);
    if (this->courseTree.search(*newCourse ) != nullptr || this->courseTree.search(*newCourse) != nullptr){
        throw TreeValueExists();
    }
    //will only reach here if everything worked
    this->courseTree.insert(*newCourse);
}

void CoursesManager::removeCourse(int CourseID)
{
    if (CourseID <= 0){
        throw InvalidInputs();
    }

    auto searchCourse = new Course(CourseID, 0);
    if (this->courseTree.search(*searchCourse) == nullptr){
        throw TreeValueNoExist();
    }

    //remove course from the courses tree
    //todo: make sure remove is added from courses tree
    //todo: remove from time tree

}

void CoursesManager::watchClass(int courseID, int classID, int time)
{
    if (courseID <= 0 || classID <=0 || time <=0 ){
        throw InvalidInputs();
    }
    Course searchCourse = Course(courseID,1);
    Course wantedCourse = (this->courseTree.search(searchCourse))->data;

    if (this->courseTree.search(wantedCourse) == nullptr){
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
    if (courseID <= 0 || classID <= 0){
        throw InvalidInputs();
    }

    Course searchCourse = Course(courseID,1);
    Node<Course> *isExistCourse = (this->courseTree.search(searchCourse));
    if (isExistCourse == nullptr){
        throw TreeValueNoExist();
    }
    Course wantedCourse = this->courseTree.search(searchCourse)->data;

    if (classID > wantedCourse.getNumOfClasses()){
        throw InvalidInputs();
    }

    Class wantedClass = wantedCourse.getClass(classID);
    *timeviewed = wantedClass.getTime();

}
