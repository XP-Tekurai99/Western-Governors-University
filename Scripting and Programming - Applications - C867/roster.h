#pragma once

#include "student.h"

using namespace std;

//class Roster;

class Roster
{
public: // No initialization
	Roster();
	~Roster();

	void add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeprogram);

	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram);
	void printByDegreeProgram();
	string getSID(int studentNo);
	//add accessor;
	//add mutator;

private:
	const int MAX_COURSES = 3;
	const int ROSTER_SIZE = 5;
	// E1: Creates an array of pointers, classRosterArray, to hold the data provided in the “studentData Table”
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
};
