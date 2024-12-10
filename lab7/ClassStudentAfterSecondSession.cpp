#include <iostream>
#include "ClassStudentAfterSecondSession.h"
using namespace std;

StudentAfterSecondSession::StudentAfterSecondSession(char *name_, int course_, int group_, char *recordNumber_) : StudentAfterFirstSession(name_, course_, group_, recordNumber_) {};

int StudentAfterSecondSession::getScore2(int index)
{
    return assessmentsSecond[index];
};

void StudentAfterSecondSession::setScore2(int index, int value)
{
    assessmentsSecond[index] = value;
};

void StudentAfterSecondSession::avarageScore()
{
    double score1 = 0;
    for (int i = 0; i < 4; i++)
    {
        score1 = score1 + getScore1(i);
    }
    double avarage_score1 = score1 / 4;

    double score2 = 0;
    for (int i = 0; i < 5; i++)
    {
        score2 = score2 + assessmentsSecond[i];
    }
    double avarage_score2 = score2 / 5;

    double avarage_score = (avarage_score1 + avarage_score2) / 2;
    cout << endl;
    cout << avarage_score1 << endl;
    cout << avarage_score2<< endl;
    cout << avarage_score;
}

ostream &operator<<(ostream &os, StudentAfterSecondSession stud)
{
    os << stud.getName() << " " << stud.getCourse() << " " << stud.getGroup() << " " << stud.getRecordNumber() << endl;
    os << "Scores after first session ";
    for (int i = 0; i < 4; i++)
    {
        os << stud.getScore1(i) << " ";
    }
    cout << endl;
    os << "Scores after second session ";
    for (int i = 0; i < 5; i++)
    {
        os << stud.getScore2(i) << " ";
    }
    return os;
}