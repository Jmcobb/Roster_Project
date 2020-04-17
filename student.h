#pragma once 
#include <string>
#include "degree.h"
using std::string;

class Student
{
public:
    const static int classArraySize = 3;

protected:
    string studentID;
    string firstName;
    string lastName;
    string email;
    string age;
    int classDays[classArraySize];
    DegreeType stype;

public:
    Student();
    Student(string ID, string firstName, string lastName, string email, string age, int classDays[]);
    string getstudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    string getAge();
    int* getClassDays();
    virtual DegreeType getDegreeType() = 0;
    void setID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(string age);
    void setClasses(int classDays[]);
    virtual void print() = 0;
    ~Student();
};