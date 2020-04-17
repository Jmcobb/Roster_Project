#pragma once 
#include <string>
#include "student.h"

class SoftwareStudent : public Student
{
    public: 
        SoftwareStudent();
        SoftwareStudent(
                string studentID,
                string firstName,
                string lastName,
                string email,
                string age,
                int classDays[],
                DegreeType degreeType);
                void print();
        DegreeType getDegreeType();
        ~SoftwareStudent();
};
