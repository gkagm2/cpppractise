#pragma
#include <iostream>
#include <stdexcept>
#include "Database.h"
using namespace std;
using namespace Records;

int DisplayMenu();
void DoHire(Database& db);
void DoFire(Database& db);
void DoPromote(Database& db);
void DoDemote(Database& db);

int main() {
	Database employeeDB;
	bool done = false;

	while (!done) {
		int selection = DisplayMenu();
		switch (selection) {
		case 1:
			DoHire(employeeDB);
			break;
		case 2:
			DoFire(employeeDB);
			break;
		case 3:
			DoPromote(employeeDB);
			break;
		case 4:
			employeeDB.DisplayAll();
			break;
		case 5:
			employeeDB.DisplayCurrent();
			break;
		case 6:
			employeeDB.DisplayFormer();
			break;
		case 0:
			done = true;
			break;
		default:
			cerr << "Unknown command.\n";
			break;
		}
	}

	return 0;
}

int DisplayMenu() {
	int selection;
	cout << "\n";
	cout << "Employee Database\n";
	cout << "------------------\n";
	cout << "1) Hire a new employee\n";
	cout << "2) Fire an employee\n";
	cout << "3) Promote an employee\n";
	cout << "4) List all employees\n";
	cout << "5) List current employees\n";
	cout << "6) List former employees\n";
	cout << "0) Quit\n";
	cout << "\n";
	cin >> selection;

	return selection;
}
void DoHire(Database& db) {
	std::string firstName;
	std::string lastName;
	cout << "First name? ";
	cin >> firstName;
	cout << "Last name? ";
	cin >> lastName;

	try {
		db.AddEmployee(firstName, lastName);
	}
	catch (const std::exception& exception) {
		cerr << "Unable to add new employee: " << exception.what() << "\n";
	}
}
void DoFire(Database& db) {
	int employeeNumber;
	cout << "Employee number? ";
	cin >> employeeNumber;
	try {
		Employee& emp = db.GetEmployee(employeeNumber);
		emp.Fire();
		cout << "Employee " << employeeNumber << " terminated.\n";
	}
	catch (const std::exception& exception) {
		cerr << "Unable to terminate employee: " << exception.what() << "\n";
	}
}

void DoPromote(Database& db) {
	int employeeNumber;
	int raiseAmount;
	cout << "Employee number? ";
	cin >> employeeNumber;
	cout << "How much of a raise? ";
	cin >> raiseAmount;
	try {
		Employee& emp = db.GetEmployee(employeeNumber);
		emp.Promote(raiseAmount);
	}
	catch (const std::exception& exception) {
		cerr << "Unable to promote  employee: " << exception.what() << "\n";
	}
}
void DoDemote(Database& db) {
	int employeeNumber;
	int demeritAmount;
	cout << "Employee number? ";
	cin >> employeeNumber;
	cout << "How mush of a demerit amount? ";
	cin >> demeritAmount;
	try {
		Employee& emp = db.GetEmployee(employeeNumber);
		emp.Demote(demeritAmount);
	}
	catch (const std::exception& exception) {
		cerr << "Unable to demote employee: " << exception.what() << "\n";
	}
}