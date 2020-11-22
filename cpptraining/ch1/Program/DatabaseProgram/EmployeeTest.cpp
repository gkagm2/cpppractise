#include <iostream>
#include "Employee.h"
using namespace std;
using namespace Records;

int main() {
	cout << "Testing the Employee class.\n";
	Employee emp;
	emp.SetFirstName("John");
	emp.SetLastName("Doe");
	emp.SetEmployeeNumber(20);
	emp.SetSalary(50000);
	emp.Promote();
	emp.Promote(1500);
	emp.Hire();
	emp.Display();
	

	return 0;
}
