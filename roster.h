#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

class Roster 
{
private:
    int lastIndex;
    int capacity;
    
public:
    Student** students;
    Roster();
    Roster(int capacity);
    
    void parseThenAdd(string row);
    void add(string sID, string sFirstName, string sLastName, string sEmail, string sAge, int dl1, int dl2, int dl3, DegreeType dt);
    void printAll();
    bool remove(string studentID);
    void printAverageDays(string studentID);
    void printInvalidEmails();
    void printByDegreeType(DegreeType d);
    
    ~Roster();
};
