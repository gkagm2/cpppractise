#include <iostream>
#include "Database.h"
using namespace std;
using namespace Records;

int main() {
	Database myDB;

	Employee& emp1 = myDB.AddEmployee("Jang", "HyeonMyeong");
	Employee& emp2 = myDB.AddEmployee("Bark", "MiSon");
	Employee& emp3 = myDB.AddEmployee("Hong", "SungWoo");

	emp1.Fire();
	emp2.SetSalary(100000);
	emp3.SetSalary(10000);
	emp3.Promote();
	cout << "All employees:\n\n";
	myDB.DisplayAll();
	cout << "\nCurrent employees:\n\n";
	myDB.DisplayCurrent();
	cout << "\nFormer employees:\n\n";
	myDB.DisplayFormer();

	return 0;
}