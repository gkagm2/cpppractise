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
		int mNextEmployeeNumber; // ���ο� �������� ���Ǿ��� �� �Ҵ��� ���� ��ȣ�� �����Ѵ�.
		
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