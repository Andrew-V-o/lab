#include <iostream>
#include "ClassStudentAfterSecondSession.h"
using namespace std;

int main(){
    StudentAfterSecondSession First{"Pol", 1, 4, "55765"};


    First.setScore1(0,5);
    First.setScore1(1,9);
    First.setScore1(2,10);
    First.setScore1(3,7);

   First.setScore2(0,7);
    First.setScore2(1,3);
    First.setScore2(2,10);
    First.setScore2(3,8);
    First.setScore2(4,8);
    cout << First;
    First.avarageScore();
    return 0;
}