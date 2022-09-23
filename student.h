#pragma once
#include <string>
#include "degree.h"

class Student {
public : 
	Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);

	int age;
	
	std::string firstName, lastName, emailAddress, studentID;

	int daysInCourse[3];

	DegreeProgram degreeProgram;

	//Student ID Getter/Setter
	std::string GetStudentID();
	void SetStudentID(std::string studentID);


	//Age getter/setter
	int GetAge();
	void SetAge(int age);


	//Days Until Completion getter/setter
	int* GetDaysInCourse();
	void SetDaysInCourse(int daysInCourse[]);


	//DegreeProgram getter/setter
	DegreeProgram GetDegree();
	void SetDegree(DegreeProgram degreeProgram);


	//First name getter/setter
	std::string GetFirstName();
	void SetFirstName(std::string firstName);

	//Last name getter/setter
	std::string GetLastName();
	void SetLastName(std::string lastName);

	//Email Adress getter/setter
	std::string GetEmail();
	void SetEmail(std::string emailAddress);

	//Print
	void Print();

	~Student();
};