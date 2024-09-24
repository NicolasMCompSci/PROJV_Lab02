#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

const string STUDENT_DATA_FILE = "StudentData.txt";
const string STUDENT_EMAILS_FILE = "StudentData_Emails.txt";

// Student struct containing student data
struct STUDENT_DATA {
	string firstName;
	string lastName;
};

int main() {
	// vector of all students saved
	vector<STUDENT_DATA> students;

	// open student data file as input
	ifstream inputFile(STUDENT_DATA_FILE);
	// checks if file was opened successfully
	if (!inputFile.is_open()) {
		cerr << "Failed to open " << STUDENT_DATA_FILE << endl;
		return 2;
	}
	
	// get line from file
	string line;
	while (getline(inputFile, line)) {
		// make line string into a stream
		stringstream currLine(line);
		// temporary student object to be added to vector
		STUDENT_DATA tempStudent;
		
		// get first name
		getline(currLine, tempStudent.lastName, ',');
		// get last name
		getline(currLine, tempStudent.firstName);

		// insert student into vector
		students.push_back(tempStudent);
	}

	return 1;
}