#pragma once 
#include <string>
#include "student.h"

class NetworkStudent : public Student
{
    public: 
        NetworkStudent();
        NetworkStudent(
                string studentID,
                string firstName,
                string lastName,
                string email,
                string age,
                int classDays[],
                DegreeType degreeType);
        DegreeType getDegreeType();
        void print();
        ~NetworkStudent();
};
