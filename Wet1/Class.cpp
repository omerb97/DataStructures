#include "Class.h"

Class::Class() {}

Class::Class(int class_id, int time)
{
    this->class_id = class_id;
    this->time = time;
}

int Class::getClassId()
{
    return class_id;
}

int Class::getTime()
{
    return time;
}

