#include <iostream>
#include <iomanip>
#include "student.h"
using std::cout;
using std::left;
using std::setw;


Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = "";
    for (int i = 0; i<classArraySize; i++) this->classDays[i] = 0;
}

Student::Student(string studentID, string firstName, string lastName, string email, string age, int classDays[])
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i<classArraySize; i++) this->classDays[i] = classDays[i];
}

string Student::getstudentID()
{
    return studentID;
}

string Student::getFirstName()
{
    return firstName;
}

string Student::getLastName()
{
    return lastName;
}

string Student::getEmail()
{
    return email;
}

string Student::getAge()
{
    return age;
}

int* Student::getClassDays()
{
    return classDays;
}

void Student::setID(string studentID)
{
    this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Student::setEmail(string email)
{
    this->email = email;
}

void Student::setAge(string age)
{
    this->age = age;
}

void Student::setClasses(int classDays[])
{
    for (int i = 0; i<classArraySize; i++) this->classDays[i] = classDays[i];   
}

void Student::print()
{
    cout << std::left << getstudentID() << "\t";
    cout << std::left << getFirstName() << "\t";
    cout << std::left  << getLastName() << "\t";
    cout << std::left  << getEmail() << "\t";
    cout << std::left << getAge() << "\t";
    int* day = getClassDays();
    cout << " " << day[0] << " " << day[1] << " " << day[2] << " ";
    switch (getDegreeType()) {
		case 0: cout << "SECURITY\n";
			break;
		case 1: cout << "NETWORKING\n";
			break;
		case 2: cout << "SOFTWARE\n";
			break;
		case 4: cout << "ERROR!\n";
			break;
	}
}

Student::~Student()
{
}
