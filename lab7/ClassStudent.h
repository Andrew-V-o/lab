#ifndef CLASS_STUDENT
#define CLASS_STUDENT
using namespace std;

class Student
{
private:
    char *name;
    int course;
    int group;
    char *recordNumber;

public:
    char *getName();

    void setName(char *p_name);

    int getCourse();

    void setCourse(int p_course);

    int getGroup();

    void setGroup(int p_group);

    char *getRecordNumber();

    Student() = delete; // запрет вызова конструктора по умолчанию

    Student(char *name_, int course_, int group_, char *recordNumber_);

    Student(const Student &p);

   friend ostream& operator<<(ostream &os, Student stud);
};

#endif