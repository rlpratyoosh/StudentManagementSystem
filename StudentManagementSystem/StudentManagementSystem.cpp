#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
protected:
	string name;
	string studentClass;
	double marks[5];
	double totalMarks = 0;
	double percentage;
public:
	vector<string> Subject = { "Physics", "Maths", "Chemistry", "English", "Painting" };
	int roll;
	void addStudentDetails();
	void displayStudentDetails();
	void updateStudentDetails();
	void calculatePercentage();
};

void Student::addStudentDetails() {
	cout << "Name: ";
	cin >> name;
	cout << "Roll: ";
	cin >> roll;
	cout << "Class: ";
	cin >> studentClass;
	for (int i = 0; i < 5; i++) {
		cout << "Enter the marks of "<< Subject[i] << ":" << endl;
		cin >> marks[i];
		totalMarks += marks[i];
	}
}

void Student::displayStudentDetails() {
	cout << "Name of the student: " << name << endl;
	cout << "Roll of the student: " << roll << endl;
	cout << "Class of the student: " << studentClass << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Marks of the student in " << Subject[i] << " is: " << marks[i] << endl;
	}
	cout << "Percentage Obtained : " << percentage << endl;
}

void Student::updateStudentDetails() {
	cout << "Old Name Is: " << name << endl;
	cout << "Enter the new name: ";
	cin >> name;	
	cout << "Old Class is: " << studentClass << endl;
	cout << "Enter the new class: ";
	cin >> studentClass;
	for (int i = 0; i < 5; i++) {
		cout << "Old Marks Obtained in " << Subject[i] << " is " << marks[i] << endl;
		cout << "Enter the new marks: " << endl;
		cin >> marks[i];
	}
}

void Student::calculatePercentage() {
	percentage = (totalMarks) / 500 * 100;
}

class StudentManagementSystem {
protected:
	vector<Student> students;
public:
	void addStudent();
	void displayAllStudent();
	void updateStudent(int);
	void searchStudent(int);
	void deleteStudent(int);
	void sortStudents();
};

void StudentManagementSystem::addStudent() {
	Student s;
	cout << "===========================================================" << endl;
	cout << "Enter the Student Details: " << endl;
	cout << "===========================================================" << endl;
	s.addStudentDetails();
	s.calculatePercentage();
	students.push_back(s);
	cout << "Student was added.." << endl;
}

void StudentManagementSystem::displayAllStudent() {
	for (Student& student : students) {
		cout << "-------------------------------------------------------" << endl;
		student.displayStudentDetails();
		cout << "-------------------------------------------------------" << endl;
	}
}

void StudentManagementSystem::searchStudent(int iroll) {
	bool found = false;
	for (Student& student : students) {
		if (iroll == student.roll) {
			student.displayStudentDetails();
			found = true;
		}
	}
	if (found = false) {
		cout << "Student was not found.." << endl;
	}

}

void StudentManagementSystem::deleteStudent(int iroll) {
	auto it = remove_if(students.begin(), students.end(), [iroll](Student& student) {
		return student.roll == iroll;
		});
	if (it != students.end()) {
		students.erase(it, students.end());
		cout << "The student has been removed..." << endl;
	}
	else {
		cout << "The student was not found..." << endl;
	}
}

void StudentManagementSystem::sortStudents() {
	sort(students.begin(), students.end(), [](Student& a, Student& b) {
		return a.roll < b.roll;
		});
	cout << "Students are sorted according to Roll Number..." << endl;
}

void StudentManagementSystem::updateStudent(int iroll) {
	cout << "===========================================================" << endl;
	cout << "Enter the Student Details: " << endl;
	cout << "===========================================================" << endl;
	bool found = false;
	for (Student& student : students) {
		if (student.roll == iroll) {
			student.updateStudentDetails();
			found = true;
		}
	}
	if (!found) {
		system("cls");
		cout << "Student not found..." << endl;
	}
}

int main() {
	StudentManagementSystem sms;
start:
	cout << "===============================================================" << endl;
	cout << "	Welcome to Student Management System (SMS)" << endl;
	cout << "===============================================================" << endl;
	cout << "Choose a Task: " << endl
		<< "1. Add a Student" << endl
		<< "2. Update a Student" << endl
		<< "3. Display All Students" << endl
		<< "4. Search a Student" << endl
		<< "5. Delete a Student" << endl
		<< "6. Sort Students" << endl
		<< "7. End" << endl;
	cout << "===============================================================" << endl;
	int op1;
	cin >> op1;
	if (op1 == 1) {
		system("cls");
		sms.addStudent();
		int op2;
		cout << "===========================================================" << endl;
		cout << "Choose : " << endl
			<< "1. Go Back" << endl
			<< "2. Quit the Portal" << endl;
		cout << "===========================================================" << endl;
		cin >> op2;
		if (op2 == 1) {
			system("cls");
			goto start;
		}
		else if (op2 == 2) {
			system("cls");
			goto end;
		}
		else {
			cout << "Wrong Input.. Ending By Default" << endl;
		}
	}

	else if (op1 == 2) {
		system("cls");
		int iroll;
		cout << "Enter the roll number of the required student" << endl;
		cin >> iroll;
		sms.updateStudent(iroll);
		int op2;
		cout << "===========================================================" << endl;
		cout << "Choose : " << endl
			<< "1. Go Back" << endl
			<< "2. Quit the Portal" << endl;
		cout << "===========================================================" << endl;
		cin >> op2;
		if (op2 == 1) {
			system("cls");
			goto start;
		}
		else if (op2 == 2) {
			system("cls");
			goto end;
		}
		else {
			cout << "Wrong Input.. Ending By Default" << endl;
		}
	}

	else if (op1 == 3) {
		system("cls");
		sms.displayAllStudent();
		int op2;
		cout << "===========================================================" << endl;
		cout << "Choose : " << endl
			<< "1. Go Back" << endl
			<< "2. Quit the Portal" << endl;
		cout << "===========================================================" << endl;
		cin >> op2;
		if (op2 == 1) {
			system("cls");
			goto start;
		}
		else if (op2 == 2) {
			system("cls");
			goto end;
		}
		else {
			cout << "Wrong Input.. Ending By Default" << endl;
		}
	}

	else if (op1 == 4) {
		system("cls");
		int iroll;
		cout << "Enter the roll number of the required student" << endl;
		cin >> iroll;
		sms.searchStudent(iroll);
		int op2;
		cout << "===========================================================" << endl;
		cout << "Choose : " << endl
			<< "1. Go Back" << endl
			<< "2. Quit the Portal" << endl;
		cout << "===========================================================" << endl;
		cin >> op2;
		if (op2 == 1) {
			system("cls");
			goto start;
		}
		else if (op2 == 2) {
			system("cls");
			goto end;
		}
		else {
			cout << "Wrong Input.. Ending By Default" << endl;
		}
	}

	else if (op1 == 5) {
		system("cls");
		int iroll;
		cout << "Enter the roll number of the required student" << endl;
		cin >> iroll;
		sms.deleteStudent(iroll);
		int op2;
		cout << "===========================================================" << endl;
		cout << "Choose : " << endl
			<< "1. Go Back" << endl
			<< "2. Quit the Portal" << endl;
		cout << "===========================================================" << endl;
		cin >> op2;
		if (op2 == 1) {
			system("cls");
			goto start;
		}
		else if (op2 == 2) {
			system("cls");
			goto end;
		}
		else {
			cout << "Wrong Input.. Ending By Default" << endl;
		}
	}

	else if (op1 == 6) {
		system("cls");
		sms.sortStudents();
		int op2;
		cout << "===========================================================" << endl;
		cout << "Choose : " << endl
			<< "1. Go Back" << endl
			<< "2. Quit the Portal" << endl;
		cout << "===========================================================" << endl;
		cin >> op2;
		if (op2 == 1) {
			system("cls");
			goto start;
		}
		else if (op2 == 2) {
			system("cls");
			goto end;
		}
		else {
			system("cls");
			cout << "Wrong Input.. Ending By Default" << endl;
		}
	}

	else if (op1 == 7) {
		system("cls");
		goto end;
	}
	
	else {
		system("cls");
		cout << "Wrong input." << endl;
		cout << "Press Enter to Try Again..." << endl;
		char c;
		c = cin.get();
		if (c == '\n') {
			system("cls");
			goto start;
		}
		else {
			goto end;
		}
	}

end:
	cout << "Quiting.." << endl;
	return 0;
}