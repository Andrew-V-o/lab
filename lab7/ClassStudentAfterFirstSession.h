#ifndef CLASS_STUDENT_AFTER_FIRST_SESSION
#define CLASS_STUDENT_AFTER_FIRST_SESSION
#include "ClassStudent.h"
using namespace std;

class StudentAfterFirstSession : public Student
{
private:
    int assessmentsFirst[4] = {0,0,0,0};

public:
    StudentAfterFirstSession(char *name_, int course_, int group_, char *recordNumber_);

    int getScore1(int index);
    void setScore1(int index, int value);

   double avarageScore();
    friend ostream& operator<<(ostream &os,StudentAfterFirstSession stud);
};

#endif