#ifndef CLASS_H
#define CLASS_H


class Class
{
private:
    int class_id;
    int time;
    int course_id;

public:
    Class();

    Class(int class_id, int course_id, int time);

    int getClassId();

    int getCourseId();

    int getTime();

    void addTime(int time);

    bool operator<(const Class c) const;

    bool operator==(const Class c) const;

};

#endif