
#include <iostream>
#include "softwareStudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent():Student()
{
    stype = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string email, string age, int classDays[], 
        DegreeType degreeType):Student(studentID, firstName, lastName, email, age, classDays)
{
    stype = SOFTWARE;
}

DegreeType SoftwareStudent::getDegreeType()
{
    return SOFTWARE;
}

void SoftwareStudent::print()
{
    this->Student::print();
}

SoftwareStudent::~SoftwareStudent()
{
    Student::~Student();
}