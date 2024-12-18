#include <iostream>
#include "ClassStudent.h"
using namespace std;

char *Student::getName()
{
    return name;
};

void Student::setName(char *p_name)
{
    name = p_name;
};

int Student::getCourse()
{
    return course;
};

void Student::setCourse(int p_course)
{
    course = p_course;
};

int Student::getGroup()
{
    return group;
};

void Student::setGroup(int p_group)
{
    group = p_group;
};

char *Student::getRecordNumber()
{
    return recordNumber;
};

Student::Student(char *name_, int course_, int group_, char *recordNumber_)
{
    name = name_;
    course = course_;
    group = group_;
    recordNumber = recordNumber_;
};

Student::Student(const Student &p)
{
    name = p.name;
    course = p.course;
    group = p.group;
    recordNumber = p.recordNumber;
}

ostream &operator<<(ostream &os, Student stud)
{
    return os << stud.getName() << " " << stud.getCourse() << " " << stud.getGroup() << " " << stud.getRecordNumber();
}

