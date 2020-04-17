#include "roster.h"
#include "degree.h"
#include <array>
using std::cout;
using std::cerr;

Roster::Roster()
{
    this->capacity = 0;
    this->lastIndex = -1;
    this->students = nullptr;
}

Roster::Roster(int capacity)
{
    this->capacity = capacity;
    this->lastIndex = -1;
    this->students = new Student*[capacity];
}

void Roster::parseThenAdd(string row)
{
    if (lastIndex < capacity)
    {
        lastIndex++;
        DegreeType degreeType;
        if (row.back() == 'Y') degreeType = SECURITY;
        else if (row.back() == 'K') degreeType = NETWORKING;
        else if (row.back() == 'E') degreeType = SOFTWARE;
        else
        {
            cerr << "INVALID STUDENT TYPE! EXITING NOW! ERROR 1\n";
            exit(-1);
        } 
        
        int rhs = row.find(",");
        string sID = row.substr(0, rhs);

        int lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string sFirstName = row.substr(lhs, rhs-lhs);

        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string sLastName = row.substr(lhs, rhs-lhs);

        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string sEmail = row.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string sAge = row.substr(lhs, rhs - lhs);

         lhs = rhs + 1;
        rhs = row.find(",", lhs);
        double dl1 = stod(row.substr(lhs, rhs - lhs));

         lhs = rhs + 1;
        rhs = row.find(",", lhs);
        double dl2 = stod(row.substr(lhs, rhs - lhs));

         lhs = rhs + 1;
        rhs = row.find(",", lhs);
        double dl3 = stod(row.substr(lhs, rhs - lhs));

        add(sID, sFirstName, sLastName, sEmail, sAge, dl1, dl2, dl3, degreeType);
    }
    else
    {
     cerr << "INVALID STUDENT TYPE! EXITING NOW! ERROR 2\n";
            exit(-1);
    }
}

void Roster::add(string sID, string sFirstName, string sLastName, string sEmail, string sAge, int dl1, int dl2, int dl3, DegreeType dt)
{
    int classDays[Student::classArraySize];
    classDays[0] = dl1;
    classDays[1] = dl2;
    classDays[2] = dl3;
    if (dt == SECURITY) students[lastIndex] = new SecurityStudent(sID, sFirstName, sLastName, sEmail, sAge, classDays, dt);
    else if (dt == NETWORKING) students[lastIndex] = new NetworkStudent(sID, sFirstName, sLastName, sEmail, sAge, classDays, dt);
    else students[lastIndex] = new SoftwareStudent(sID, sFirstName, sLastName, sEmail, sAge, classDays, dt);
}

void Roster::printAll()
{
    for (int i = 0; i <= this->lastIndex; i++)(this->students)[i]->print();
}

bool Roster::remove(string studentID)
{
  bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
            if (this->students[i]->getstudentID() == studentID) {
                found = true;
                Student* stu = students[i];
                this->students[i] = this->students[lastIndex];
                (students[lastIndex]) = stu;
		            lastIndex--;
            }
    }
    return found;
}

void Roster::printAverageDays(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (this->students[i]->getstudentID() == studentID) {
            found = true;
            int* d = students[i]->getClassDays();
            cout << "Student ID: " << studentID << ", averages " << (d[0] + d[1] + d[2]) / 3 << " days in a course.\n";
        }
    }
    if (!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmails()
{
    cout << "\n";
    for (int i = 0; i < 5; i++) {
	bool foundAt = false;
	bool foundPeriod = false;
	bool foundSpace = false;
        string email = "";
        email = students[i]->getEmail();
		for (char &c : email) {
                    if (c == '@') {
                        foundAt = true;
                    }
                    if (c == '.') {
                        foundPeriod = true;
                    }
                    if (c == ' ') {
                        foundSpace = true;
                    }
		}
                if (foundAt == false) {
                    cout << students[i]->getEmail() << "\n";
                }
                if (foundPeriod == false) {
                    cout << students[i]->getEmail() << "\n";
                }
                if (foundSpace == true) {
                    cout << students[i]->getEmail() << "\n";
		}
    };
}

void Roster::printByDegreeType(DegreeType d) {
    for (int i = 0; i <= lastIndex; i++) 
    {
            if (this->students[i]->getDegreeType() == d) 
                this->students[i]->print();
    }
}

Roster::~Roster() {
    for (int i = 0; i < lastIndex; i++) 
    {
        delete this->students[i];
    }
    delete this;
}

int main() 
{
    cout << "SCRIPTING AND PROGRAMMING APPLICATIONS — C867\n";
    cout << "C++\n";
    int classRosterArray = 5;
    const string studentData[] =
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,James,Cobb,j.morgan.cobb@gmail.com,23,20,60,12,SOFTWARE"};
    Roster * classRoster = new Roster(classRosterArray);
    cout << "Parsing data and adding students:\t";
    for(int i = 0; i < classRosterArray; i++)
    {
        classRoster->parseThenAdd(studentData[i]);
    }
    cout << "Done!\n";
    cout << "Displaying all Students:\n";
    classRoster->printAll();
    cout << "\n";
    cout << "Printing Invalid Email entries:\n";
    classRoster->printInvalidEmails();
    cout << "\n";
    cout << "Printing Average Days left for Students:\n";
    classRoster->printAverageDays("A1");
    classRoster->printAverageDays("A2");
    classRoster->printAverageDays("A3");
    classRoster->printAverageDays("A4");
    classRoster->printAverageDays("A5");
    cout << "\n";
    cout << "Now printing by Degree Program: SOFTWARE:\n";
    classRoster->printByDegreeType(SOFTWARE);
    cout << "\n";   
    cout << "Removing A3:\n";
    switch(classRoster->remove("A3"))
    {
        case 1: classRoster->printAll();
			break;
		case 0: cout << "Student not found!\n";
			break;
    };    
    cout << "\n";   
    cout << "Removing A3:\n";
    switch(classRoster->remove("A3"))
    {
        case 1: classRoster->printAll();
			break;
		case 0: cout << "Student not found!\n";
			break;
    };
    classRoster->~Roster();
    return 0;
}

