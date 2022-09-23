#include <iostream>
#include "Roster.h"

/*

Course: SCRIPTING AND PROGRAMMING - APPLICATIONS — C867

Language used: C++

Student ID: ****

Student Name: Nathaniel Unruh


*/

int main()
{

	const std::string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Nathaniel,Unruh,nunruh@wgu.edu,26,5,7,13,SOFTWARE" };

	int studentCount = sizeof(studentData) / sizeof(*studentData);

	Roster classRoster(studentCount);

	for (int i = 0; i < studentCount; i++) {

		classRoster.parseData(studentData[i]);
	}


	std::cout << "Course: SCRIPTING AND PROGRAMMING APPLICATIONS C867" << std::endl;

	std::cout << "Language used: C++" << std::endl;

	std::cout << "Student ID: ***" << std::endl;

	std::cout << "Student Name: Nathaniel Unruh" << std::endl << std::endl;

	std::cout << "Printing all students " << std::endl << std::endl;
	
	classRoster.printAll();

	std::cout << "Printing all invalid emails " << std::endl << std::endl;
	classRoster.printInvalidEmails();

	std::cout << "Printing average days in course " << std::endl << std::endl;
	for (int i = 0; i < studentCount; i++) {
		
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
	
	}

	std::cout << "Printing by degree program " << std::endl << std::endl;
	classRoster.printByDegreeProgram(SOFTWARE);


	
	std::cout << "Removing student A3 " << std::endl << std::endl;
	classRoster.remove("A3");

	std::cout << "Printing all students " << std::endl << std::endl;
	classRoster.printAll();

	std::cout << "Attempting to remove student A3 again " << std::endl << std::endl;
	classRoster.remove("A3");

}
