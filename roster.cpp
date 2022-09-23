#include "roster.h"
#include <iostream>

Roster::Roster(int rosterSize) {

	index = 0;

	this->rosterSize = rosterSize;

	this->classRosterArray = new Student * [rosterSize];

};

Roster::~Roster() {

	std::cout << "Running destructor" << std::endl << std::endl;

	for (int i = 0; i < index; i++) {

		delete this->classRosterArray[i];
	
	}


	delete classRosterArray;

};

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

	int daysInCourse[3];
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;

	this->classRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);

	index++;


};

void Roster::remove(std::string studentID) {

	bool isFound = false;

	for (int i = 0; i < index; i++) {

		std::string idCheck = (this->classRosterArray)[i]->GetStudentID();


		if (studentID.compare(idCheck) == 0) {

			delete this->classRosterArray[i];

			classRosterArray[i] = classRosterArray[index - 1];

			isFound = true;

			index--;

		}
	
	}


	if (isFound) {
		std::cout << "Student " << studentID << " removed." << std::endl << std::endl;
	}
	else {
		std::cout << "Student " << studentID << " not found" << std::endl << std::endl;
	}
};

void Roster::printAll() {

	for (int i = 0; i < index; i++) {

		this->classRosterArray[i]->Print();
	
	}

};

void Roster::printAverageDaysInCourse(std::string studentID) {

	int * daysInCourse;

	for (int i = 0; i < index; i++) {

		std::string idCheck = this->classRosterArray[i]->GetStudentID();

		if (studentID.compare(idCheck) == 0) {

			daysInCourse = classRosterArray[i]->GetDaysInCourse();

			std::cout << "Average days in course for student " << studentID << " is " << (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3 << std::endl << std::endl;

		}

	}

};

void Roster::printInvalidEmails() {
	
	for (int i = 0; i < index; i++) {

		bool bContainsSpace = false;
		std::string emailCheck = this->classRosterArray[i]->GetEmail();

		//Check for spaces
		for (int i = 0; i < emailCheck.size(); i++) {

			if (isspace(emailCheck[i])) {

				bContainsSpace = true;

			}

		}

		//Check for '@' and '.' symbols
		auto atSymbol = std::find(emailCheck.begin(), emailCheck.end(), '@');
		auto period = std::find(atSymbol, emailCheck.end(), '.');

		if ((atSymbol == emailCheck.end() || period == emailCheck.end()) || bContainsSpace) {

			std::cout << "Student " << this->classRosterArray[i]->GetStudentID() << " email " << emailCheck << " is invalid" << std::endl << std::endl;

		}

	}

};

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	for (int i = 0; i < index; i++) {

		if ((classRosterArray[i]->GetDegree()) == degreeProgram) {

			classRosterArray[i]->Print();

		}

	}

};

void Roster::parseData(std::string str) {

	std::string stringArray[9];

	std::string studentID, firstName, lastName, emailAddress, degreeProgram;

	int age, daysInCourse1, daysInCourse2, daysInCourse3;

	int pos = 0, i = 0;
	
	//Split the input string into multiple substrings held in an array
	while ((pos = str.find(',')) != std::string::npos) {

		stringArray[i] = str.substr(0, pos);

		i++;

		str.erase(0, pos + 1);
	
	}

	//Assign array elements to variables
	studentID = stringArray[0];

	firstName = stringArray[1];

	lastName = stringArray[2];

	emailAddress = stringArray[3];

	age = std::stoi(stringArray[4]);

	daysInCourse1 = std::stoi(stringArray[5]);

	daysInCourse2 = std::stoi(stringArray[6]);

	daysInCourse3 = std::stoi(stringArray[7]);

	degreeProgram = str;

	if (degreeProgram == "SECURITY") {

		add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, SECURITY);

	}
	else if (degreeProgram == "NETWORK") {

		add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, NETWORK);

	}
	else if (degreeProgram == "SOFTWARE") {

		add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, SOFTWARE);

	}

}
