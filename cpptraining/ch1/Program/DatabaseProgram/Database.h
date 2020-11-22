#pragma once
#include <iostream>
#include <vector>
#include "Employee.h"

namespace Records {
	class Database
	{
	private:
		const int kFirstEmployeeNumber = 1000;
	private:
		std::vector<Employee> mEmployees;
		int mNextEmployeeNumber; // 새로운 종업원이 고용되었을 때 할당할 고유 번호를 저장한다.
		
	public:
		Database();
		Employee& AddEmployee(const std::string& firstName, const std::string& lastName);
		Employee& GetEmployee(int employeeNumber);
		Employee& GetEmployee(const std::string& firstname, const std::string& lastName);

		void DisplayAll() const;
		void DisplayCurrent() const;
		void DisplayFormer() const;
	};
}