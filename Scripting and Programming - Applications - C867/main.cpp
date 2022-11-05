#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "roster.h"

using namespace std;

void courseHeader()
{
	// F1: Course Information
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: #001235275" << endl;
	cout << "Name: Taeshawn Threatt" << endl << endl;
}

int main() {
	const int ROSTER_SIZE = 5;
	const string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Taeshawn,Threatt,sthrea5@wgu.edu,23,48,56,52,SOFTWARE" }; // A: Includes Personal Information

	DegreeProgram degreeProgram;

	// F1: Prints out course information to the screen
	courseHeader();

	// F2: Creates an instance of the Roster class called classRoster
	Roster classRoster;

	string studentID;

	// F3: Adds each student to classRoster
//	string input = studentData[i];
	cout << "Adding Students to Roster: ";
	for (int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++) {
		string input = studentData[i];
		istringstream ss(input);
		string token;
		string rAddDat[9];

		int j = 0;
		while (getline(ss, token, ','))
		{
			rAddDat[j] = token;
			j += 1;
		}

		if (rAddDat[8] == "SECURITY")
		{
			degreeProgram = SECURITY;
		}
		else if (rAddDat[8] == "NETWORK")
		{
			degreeProgram = NETWORK;
		}
		else if (rAddDat[8] == "SOFTWARE")
		{
			degreeProgram = SOFTWARE;
		}
		else
		{
			degreeProgram = UNDECLARED;
		}

		cout << "Calling add for " << rAddDat[0] << ", ";
		classRoster.add(rAddDat[0],
			rAddDat[1],
			rAddDat[2],
			rAddDat[3],
			std::stoi(rAddDat[4]),
			std::stoi(rAddDat[5]),
			std::stoi(rAddDat[6]),
			std::stoi(rAddDat[7]),
			degreeProgram);
	}

	cout << endl;

	// F4: Converts pseudo code to complete the main() function
	cout << endl << "Calling printAll():" << endl;
	classRoster.printAll();

	cout << endl << "Calling printInvalidEmails():" << endl;
	classRoster.printInvalidEmails();

	// Loops through classRosterArray and for each element
	cout << endl << "Calling printAverageDaysInCourse() for each student:" << endl;
	for (int i = 0; i < ROSTER_SIZE; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.getSID(i));
	}

	cout << endl << "Calling printByDegreeProgram(SOFTWARE):" << endl;
	classRoster.printByDegreeProgram(SOFTWARE);

	cout << endl << "Calling remove(A3):" << endl;
	classRoster.remove("A3");

	cout << endl << "Calling printAll():" << endl;
	classRoster.printAll();

	cout << endl << "Calling remove(A3):" << endl;
	classRoster.remove("A3");
}
