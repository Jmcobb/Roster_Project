#include <iostream>
#include "securityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent():Student()
{
    stype = SECURITY;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string email, string age, int classDays[], 
        DegreeType degreeType):Student(studentID, firstName, lastName, email, age, classDays)
{
    stype = SECURITY;
}

DegreeType SecurityStudent::getDegreeType()
{
    return SECURITY;
}

void SecurityStudent::print()
{
    this->Student::print();
}

SecurityStudent::~SecurityStudent()
{
    Student::~Student();
}