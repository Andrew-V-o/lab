#include <iostream>
#include "ClassStudentAfterFirstSession.h"
using namespace std;

StudentAfterFirstSession::StudentAfterFirstSession(char *name_, int course_, int group_, char *recordNumber_) : Student(name_, course_, group_, recordNumber_) {};

int StudentAfterFirstSession::getScore1(int index)
{
    return assessmentsFirst[index];
};

void StudentAfterFirstSession::setScore1(int index, int value)
{
    assessmentsFirst[index] = value;
};

double StudentAfterFirstSession::avarageScore()
{
    double score = 0;
    for (int i = 0; i < 4; i++)
    {
        score = score + assessmentsFirst[i];
        
    }
    double avarage_score1 = score / 4;
    cout << avarage_score1;
    return avarage_score1;
}

ostream &operator<<(ostream &os, StudentAfterFirstSession stud)
{
    os << stud.getName() << " " << stud.getCourse() << " " << stud.getGroup() << " " << stud.getRecordNumber() << endl;
    os << "Scores ";
    for (int i = 0; i < 4; i++)
    {
        os << stud.getScore1(i) << " ";
    }
    return os;
}