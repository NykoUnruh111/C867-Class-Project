#include "student.h"
#include <iostream>

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {

	this->studentID = studentID;
	this->age = age;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->degreeProgram = degreeProgram;

	for (int i = 0; i < 3; i++) {

		this->daysInCourse[i] = daysInCourse[i];

	}

};

Student::~Student() {


};

//Student ID Getter/Setter
std::string Student::GetStudentID() {

	return studentID;

};

void Student::SetStudentID(std::string studentID) {

	this->studentID = studentID;

};


//Age getter/setter
int Student::GetAge() {

	return age;

}

void Student::SetAge(int age) {

	this->age = age;

}


//Days Until Completion getter/setter
int * Student::GetDaysInCourse() {

	return daysInCourse;

}

void Student::SetDaysInCourse(int daysInCourse[]) {

	for (int i = 0; i < 3; i++) {

		this->daysInCourse[i] = daysInCourse[i];

	}

}


//DegreeProgram getter/setter
DegreeProgram Student::GetDegree() {

	return degreeProgram;

}

void Student::SetDegree(DegreeProgram degreeProgram) {

	this->degreeProgram = degreeProgram;

}

//First name getter/setter
std::string Student::GetFirstName() {

	return firstName;

}

void Student::SetFirstName(std::string firstName) {

	this->firstName = firstName;

}

//Last name getter/setter
std::string Student::GetLastName() {

	return lastName;

}

void Student::SetLastName(std::string lastName) {

	this->lastName = lastName;

}

//Email Adress getter/setter
std::string Student::GetEmail() {

	return emailAddress;

}

void Student::SetEmail(std::string emailAddress) {

	this->emailAddress = emailAddress;

}

//Print
void Student::Print() {

	std::cout << "\tStudentID: " << studentID << std::endl;
	
	std::cout << "\tFirst name: " << firstName << std::endl; 
	
	std::cout << "\tLast name: " << lastName << std::endl;

	std::cout << "\tAge: " << age << std::endl;
	
	std::cout << "\tdaysInCourse: " << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << std::endl;
	
	std::cout << "\tDegree program: " << degreeProgramStrings[degreeProgram] << std::endl << std::endl;		
	
}
