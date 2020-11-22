#include <iostream>
#include <stdexcept>
#include "Database.h"
using namespace std;

namespace Records {
	Database::Database() {}
	Employee & Database::AddEmployee(const std::string & firstName, const std::string & lastName)
	{
		Employee theEmployee;
		theEmployee.SetFirstName(firstName);
		theEmployee.SetLastName(lastName);
		theEmployee.SetEmployeeNumber(mNextEmployeeNumber++);
		theEmployee.Hire();
		mEmployees.push_back(theEmployee);
		return mEmployees[mEmployees.size() - 1];
	}
	Employee & Database::GetEmployee(int employeeNumber)
	{
		for (auto& employee : mEmployees) {
			if (employee.GetEmployeeNumber() == employeeNumber)
				return employee;
		}
		throw runtime_error("No employee found.");
	}
	Employee & Database::GetEmployee(const std::string & firstname, const std::string & lastName)
	{
		for (auto& employee : mEmployees) {
			if (employee.GetFirstName() == firstname && employee.GetLastName() == lastName)
				return employee;
		}
		throw runtime_error("No employee found.");
	}
	void Database::DisplayAll() const
	{
		for (const auto& employee : mEmployees) {
			employee.Display();
		}
	}
	void Database::DisplayCurrent() const
	{
		for (const auto& employee : mEmployees) {
			if (employee.GetIsHired())
				employee.Display();
		}
	}
	void Database::DisplayFormer() const
	{
		for (const auto& employee : mEmployees) {
			if (!employee.GetIsHired())
				employee.Display();
		}
	}
}