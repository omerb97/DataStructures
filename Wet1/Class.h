#ifndef CLASS_H
#define CLASS_H


class Class
{
private:
    int class_id;
    int time;

public:
    Class();

    Class(int class_id, int time);

    int getClassId();

    int getTime();

    void addTime(int time);

};

#endif