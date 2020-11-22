#include <iostream>
#include "Employee.h"
using namespace std;

namespace Records {
	Employee::Employee() :
		mFirstName(""),
		mLastName(""),
		mEmployeeNumber(-1),
		mSalary(kDefaultStartingSalary),
		mIsHired(false)	
	{}
	void Employee::Promote(int raiseAmount)
	{
		SetSalary(GetSalary() + raiseAmount);
	}
	void Employee::Demote(int demeritAmount)
	{
		SetSalary(GetSalary() - demeritAmount);
	}
	void Employee::Hire()
	{
		mIsHired = true;
	}

	void Employee::Fire()
	{
		mIsHired = false;
	}
	void Employee::Display() const
	{
		cout << "Employee: " << GetLastName() << ", " << GetFirstName() << "\n";
		cout << "-----------------------------\n";
		cout << (mIsHired ? "Current Employee" : "Former Employee") << "\n";
		cout << "Employee number : " << GetEmployeeNumber() << "\n";
		cout << "Salay : $" << GetSalary() << "\n";
		cout << "\n";
	}
	void Employee::SetFirstName(const std::string & firstName)
	{
		mFirstName = firstName;
	}
	const std::string & Employee::GetFirstName() const
	{
		return mFirstName;
	}
	void Employee::SetLastName(const std::string & lastName)
	{
		mLastName = lastName;
	}
	const std::string & Employee::GetLastName() const
	{
		return mLastName;
	}
	void Employee::SetEmployeeNumber(int employNumber)
	{
		mEmployeeNumber = employNumber;
	}
	int Employee::GetEmployeeNumber() const
	{
		return mEmployeeNumber;
	}
	void Employee::SetSalary(int newSalary)
	{
		mSalary = newSalary;
	}
	int Employee::GetSalary() const
	{
		return mSalary;
	}
	bool Employee::GetIsHired() const
	{
		return mIsHired;
	}
}
