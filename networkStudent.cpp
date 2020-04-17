#include <iostream>
#include "networkStudent.h"
using std::cout;

NetworkStudent::NetworkStudent():Student()
{
    stype = NETWORKING;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string email, string age, int classDays[], 
        DegreeType degreeType):Student(studentID, firstName, lastName, email, age, classDays)
{
    stype = NETWORKING;
}

DegreeType NetworkStudent::getDegreeType()
{
    return NETWORKING;
}

void NetworkStudent::print()
{
    this->Student::print();
}

NetworkStudent::~NetworkStudent()
{
    Student::~Student();
}