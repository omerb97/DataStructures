#include "CoursesManager.h"

void CoursesManager::addCourse(int courseID)
{
    if (courseID <= 0)
    {
        throw InvalidInputs();
    }
    Course newCourse(courseID);
    if (this->courses.Search(newCourse) != nullptr)
    {
        throw ValueExists();
    }
    //will only reach here if everything worked
    this->courses.Insert(newCourse);
}

void CoursesManager::removeCourse(int courseID)
{
    if (courseID <= 0)
    {
        throw InvalidInputs();
    }

    Course searchCourse(courseID);
    if (this->courses.Search(searchCourse) == nullptr)
    {
        throw ValueNoExist();
    }
    Course wantedCourse = this->courses.Search(searchCourse)->GetData();
    int numOfClasses = wantedCourse.getNumOfClasses();
    for (int i = 0; i < numOfClasses; i++)
    {
        if (timeTree.search(wantedCourse.getClass(i)) != nullptr)
        {
            watchedClasses--;
            this->timeTree.deleteNode(wantedCourse.getClass(i));
        }
    }
    totalClasses = totalClasses - wantedCourse.getNumOfClasses();
    this->courseTree.deleteNode(wantedCourse);
}

void CoursesManager::watchClass(int courseID, int classID, int time)
{
    if (courseID <= 0 || classID < 0 || time <= 0) {
        throw InvalidInputs();
    }
    Course searchCourse(courseID);
    Course* wantedCourse = (&((this->courses.Search(searchCourse))->GetData()));

    if (wantedCourse == nullptr) {
        throw ValueNoExist();
    }
    if ((classID + 1) > wantedCourse->getNumOfClasses()) {
        throw InvalidInputs();
    }

    Class* wantedClass = &(wantedCourse->getClass(classID));

    if (wantedClass->getTime() != 0) {
        this->timeTree.deleteNode(wantedClass);
        wantedClass->addTime(time);
        this->timeTree.insert(wantedClass);
    }
    if (wantedClass->getTime() == 0) {
        wantedClass->addTime(time);
        watchedClasses++;
        this->timeTree.insert(wantedClass);
    }
}

void CoursesManager::timeViewed(int courseID, int classID, int* timeviewed)
{
    if (courseID <= 0 || classID < 0) {
        throw InvalidInputs();
    }

    Course searchCourse(courseID);
    ListNode<Course>* isExistCourse = (this->courses.Search(searchCourse));
    if (isExistCourse == nullptr)
    {
        throw ValueNoExist();
    }
    Course wantedCourse = isExistCourse->GetData();

    if ((classID + 1) > wantedCourse.getNumOfClasses())
    {
        throw InvalidInputs();
    }

    Class wantedClass = wantedCourse.getClass(classID);
    *timeviewed = wantedClass.getTime();
}

void CoursesManager::getIthWatchedClass(int i, int* courseID, int* classID)
{
    if (i <= 0)
    {
        throw InvalidInputs();
    }
    if (i > watchedClasses)
    {
        throw TooManyClasses();
    }

    Class ithClass = timeTree.findIthMax(i);

    (*courseID) = ithClass.getCourseId();
    (*classID) = ithClass.getClassId();
}

void CoursesManager::addClass(int courseID, int *classID)
{
    if (courseID <= 0)
    {
        throw InvalidInputs();
    }

    Course searchCourse(courseID);
    if (this->courses.Search(searchCourse) == nullptr)
    {
        throw ValueNoExist();
    }
    Course* wantedCourse = &(this->courses.Search(searchCourse)->GetData());

    *classID = wantedCourse->getNumOfClasses();
    wantedCourse->addClass();

    totalClasses++;
}
