#include "library.h"
#include "CoursesManager.h"

void* Init()
{
    try {
        CoursesManager *DS = new CoursesManager();
        return (void*) DS;
    }
    catch (const Exception& e){
        return nullptr;
    }
}

StatusType AddCourse (void *DS, int courseID, int numOfClasses)
{
    if (DS == nullptr){
        return INVALID_INPUT;
    }
    try{
        auto targetManager = (CoursesManager*) DS;
        targetManager->addCourse(courseID, numOfClasses);
    }
    catch (const InvalidInputs& e){
        return INVALID_INPUT;
    }
    catch (const TreeValueExists& e){
        return FAILURE;
    }
    return SUCCESS;
}

StatusType RemoveCourse(void *DS, int courseID)
{
    if (DS == nullptr){
        return INVALID_INPUT;
    }
    try{
        auto targetManager = (CoursesManager*) DS;
        targetManager->removeCourse(courseID);
    }
    catch (const InvalidInputs& e){
        return INVALID_INPUT;
    }
    catch (const TreeValueNoExist& e){
        return FAILURE;
    }
    return SUCCESS;
}

StatusType WatchClass(void *DS, int courseID, int classID, int time)
{
    if (DS == nullptr){
        return INVALID_INPUT;
    }
    try{
        auto targetManager = (CoursesManager*) DS;
        targetManager->watchClass(courseID, classID, time);
    }
    catch (const InvalidInputs& e){
        return INVALID_INPUT;
    }
    catch (const TreeValueNoExist& e){
        return FAILURE;
    }
    return SUCCESS;
}

StatusType TimeViewed(void *DS, int courseID, int classID, int *timeViewed)
{
    if (DS == nullptr){
        return INVALID_INPUT;
    }
    try{
        auto targetManager = (CoursesManager*) DS;
        targetManager->timeViewed(courseID, classID, timeViewed);
    }
    catch (const InvalidInputs& e){
        return INVALID_INPUT;
    }
    catch (const TreeValueNoExist& e){
        return FAILURE;
    }
    return SUCCESS;
}