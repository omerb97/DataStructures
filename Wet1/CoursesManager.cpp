#include "CoursesManager.h"


//CoursesManager::~CoursesManager() {
//    //todo: is this the correct way to do it or should we do it some default way
//    auto *deleteTime = &(this->timeTree);
//    delete deleteTime;
//    auto *deleteCourses = &(this->courseTree);
//    delete deleteCourses;
//}

void CoursesManager::addCourse( int courseID, int numOfClasses)
{
    if (courseID <=0 || numOfClasses <= 0)
    {
        throw InvalidInputs();
    }
    auto newCourse = Course(courseID, numOfClasses);
    if (this->courseTree.search(newCourse ) != nullptr || this->courseTree.search(newCourse) != nullptr)
    {
        throw TreeValueExists();
    }
    //will only reach here if everything worked
    this->courseTree.insert(newCourse);
}

void CoursesManager::removeCourse(int CourseID)
{
    if (CourseID <= 0)
    {
        throw InvalidInputs();
    }

    auto searchCourse = Course(CourseID, 1);
    if (this->courseTree.search(searchCourse) == nullptr){
        throw TreeValueNoExist();
    }
    auto wantedCourse = this->courseTree.search(searchCourse)->data;
    int numOfClasses = wantedCourse.getNumOfClasses();
    for (int i=0; i < numOfClasses; i++){
        //todo: check ptr array
        //todo: do a loop to delete all courses
    }

    this->courseTree.deleteNode(searchCourse);

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

    Class wantedClass = wantedCourse.getClass(classID);
    //todo: the function wnated class returns by value? so maybe if we change some value here it wont change it?
    if (wantedClass.getTime() != 0){
        this->timeTree.deleteNode(wantedClass);
        wantedClass.addTime(time);
        this->timeTree.insert(wantedClass);
    }
    if (wantedClass.getTime() == 0){
        wantedClass.addTime(time);
        this->timeTree.insert(wantedClass);
    }
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


