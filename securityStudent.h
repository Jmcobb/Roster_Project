#pragma once 
#include <string>
#include "student.h"

class SecurityStudent : public Student
{
    public: 
        SecurityStudent();
        SecurityStudent(
                string studentID,
                string firstName,
                string lastName,
                string email,
                string age,
                int classDays[],
                DegreeType degreeType);
        DegreeType getDegreeType(); 
        void print();
        ~SecurityStudent();
};