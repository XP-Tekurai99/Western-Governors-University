#pragma once

#include "degree.h"

using namespace std;

class Student
{
public:
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* courseDays, DegreeProgram degreeProgram);
	~Student();
	string getStudentID();
	void setStudentID(string newStudentID);
	string getFirstName();
	void setFirstName(string newFirstName);
	string getLastName();
	void setLastName(string newLastName);
	string getEmailAddress();
	void setEmailAddress(string newEmailAddress);
	int validateEmailAddress();
	int getAge();
	void setAge(int newAge);
	int* getDaysInCourse();
	void setDaysInCourse(int* daysInCourseVal);
	void setDaysInCourse(int index, int days);
	DegreeProgram getDegreeProgram();
	string getDegreeProgram(string str);
	void setDegreeProgram(DegreeProgram newDegProg);
	void print();
	float getAverageDaysInCourses();


private:
	const int MAX_COURSES = 3;
	//	const int FIELDS = 9;
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3] = { 189, 189, 189 };
	DegreeProgram degreeProgram;
};
