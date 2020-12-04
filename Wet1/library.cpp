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