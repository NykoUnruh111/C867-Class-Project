#pragma once
#include "degree.h"
#include <string>
#include "student.h"

class Roster {

	int index;

	int rosterSize;

public : 
	Roster(int rosterSize);
	
	~Roster();

	Student ** classRosterArray;

	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

	void remove(std::string studentID);
	
	void printAll();

	void printAverageDaysInCourse(std::string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degreeProgram);

	void parseData(std::string str);
};