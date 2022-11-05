#include <iostream>
//#include <cctype>
//#include <vector>
//#include <array>
#include <string>

#include "roster.h"

using namespace std;

Roster::Roster()
{
}

Roster::~Roster()
{
	// Deletes the students in the Roster
	int i = 0;
	for (i = 0; i < ROSTER_SIZE; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

void Roster::add(string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourse1,
	int daysInCourse2,
	int daysInCourse3,
	DegreeProgram degreeprogram)
{
	// E3:  public void add(string studentID,
	// string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
	// int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
	// sets the instance variables from D1 and updates the roster

	int courseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	for (int i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student(studentID,
				firstName,
				lastName,
				emailAddress,
				age,
				courseDays,
				degreeprogram);
			break;
		}
	}

}

void Roster::remove(string studentID)
{
	// E3b:  public void remove(string studentID) removes students from the roster by student ID.
	// If the student ID does not exist, the function prints an error message

	int i = 0;
	bool j = false;
	for (i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i] == nullptr) {
		}
		else {
			if (classRosterArray[i]->getStudentID() == studentID) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				j = true;
			}
		}
	}
	if (j == false) {
		cout << "ERROR - Student: " << studentID << " not found." << endl;
	}
}

void Roster::printAll()
{
	// E3c: public void printAll() prints a complete tab-separated list of student data in the provided format:
	// [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab] daysInCourse: {35, 40, 55} Degree Program: Security
	// The printAll() function should loop through all the students in classRosterArray and call the print() function for each student

	int i = 0;
	//cout << "This class conatins these students:" << endl;
	for (i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i] == nullptr) {
		}
		else {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	// E3d: public void printAverageDaysInCourse(string studentID) prints a student’s average
	// number of days in the three courses.The student is identified by the studentID parameter.

	int stuIDX;

	for (int i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			stuIDX = i;
		}
	}
	cout << "Student " << classRosterArray[stuIDX]->getStudentID() << " "
		<< " has averaged "
		<< classRosterArray[stuIDX]->getAverageDaysInCourses()
		<< " day(s) per course for the last three courses." << endl;
}

void Roster::printInvalidEmails()
{
	// E3e: public void printInvalidEmails() verifies student email addresses and
	// displays all invalid email addresses to the user

	int i = 0;
	cout << "Invalid email addresses:" << endl;
	for (i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i]->validateEmailAddress() == 1) {
			cout << classRosterArray[i]->getEmailAddress() << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram byDegreeProgram)
{
	// E3f: public void printByDegreeProgram(DegreeProgram degreeProgram) prints out
	// student information for a degree program specified by an enumerated type

	int i = 0;
	for (i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i]->getDegreeProgram() == byDegreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printByDegreeProgram()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROSTER_SIZE; i++) {
		for (j = 0; j < ROSTER_SIZE; j++) {
			if (classRosterArray[i]->getDegreeProgram() == NETWORK) {
				classRosterArray[i]->print();
			}
		}
		for (j = 0; j < ROSTER_SIZE; j++) {
			if (classRosterArray[i]->getDegreeProgram() == SECURITY) {
				classRosterArray[i]->print();
			}
		}
		for (j = 0; j < ROSTER_SIZE; j++) {
			if (classRosterArray[i]->getDegreeProgram() == SOFTWARE) {
				classRosterArray[i]->print();
			}
		}
		for (j = 0; j < ROSTER_SIZE; j++) {
			if (classRosterArray[i]->getDegreeProgram() == UNDECLARED) {
				classRosterArray[i]->print();
			}
		}
	}
}

string Roster::getSID(int studentNo)
{
	return classRosterArray[studentNo]->getStudentID();
}
