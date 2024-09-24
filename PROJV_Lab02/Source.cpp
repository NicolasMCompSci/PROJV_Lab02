#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// define PreRealse compiler directive
#define PreRelease

// constant name for files to be accessed
const string STUDENT_DATA_FILE = "StudentData.txt";
const string STUDENT_EMAILS_FILE = "StudentData_Emails.txt";

// Student struct containing student data
struct STUDENT_DATA {
	string firstName;
	string lastName;
#ifdef PreRelease
	string email;
#endif
};

int main() {
	// vector of all students saved
	vector<STUDENT_DATA> students;

#ifdef PreRelease	// pre-release code
	// open student data file as input
	ifstream inputFile(STUDENT_EMAILS_FILE);
	// checks if file was opened successfully
	if (!inputFile.is_open()) {
		cerr << "Failed to open " << STUDENT_EMAILS_FILE << endl;
		return 2;
	}
#else	// non-pre-release code
	// open student data file as input
	ifstream inputFile(STUDENT_DATA_FILE);
	// checks if file was opened successfully
	if (!inputFile.is_open()) {
		cerr << "Failed to open " << STUDENT_DATA_FILE << endl;
		return 2;
	}
#endif
	
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
		getline(currLine, tempStudent.firstName, ',');
		#ifdef PreRelease // get email if in pre-release
		getline(currLine, tempStudent.email, ',');
		#endif // PreRelease

		// insert student into vector
		students.push_back(tempStudent);
		#ifdef _DEBUG // print out each added student if in debug mode
			cout << tempStudent.firstName << " " << tempStudent.lastName << " added." << endl;
		#endif
	}

	return 1;
}