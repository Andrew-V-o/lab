#ifndef CLASS_STUDENT_AFTER_SECOND_SESSION
#define CLASS_STUDENT_AFTER_SECOND_SESSION
#include "ClassStudentAfterFirstSession.h"
using namespace std;

class StudentAfterSecondSession : public StudentAfterFirstSession
{
private:
    int assessmentsSecond[5] = {0,0,0,0,0};

public:
    StudentAfterSecondSession(char *name_, int course_, int group_, char *recordNumber_);

    int getScore2(int index);
    void setScore2(int index, int value);

    void avarageScore();

    friend ostream &operator<<(ostream &os, StudentAfterSecondSession stud);
};

#endif