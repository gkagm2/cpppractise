#pragma
#include<string>
namespace Records {
	class Employee {
	private:
		const int kDefaultStartingSalary = 3000;
	private:
		std::string mFirstName;
		std::string mLastName;
		int mEmployeeNumber;
		int mSalary;
		bool mIsHired;

		
	public:
		Employee();

		void Promote(int raiseAmount = 1000);
		void Demote(int demeritAmount = 1000);
		void Hire(); // 종업원 채용 또는 재채용
		void Fire(); // 종업원 해고 
		void Display() const; // 콘솔에 종업원 정보 출력

		// getter and setter
		void SetFirstName(const std::string& firstName);
		const std::string& GetFirstName() const;

		void SetLastName(const std::string& lastName);
		const std::string& GetLastName() const;

		void SetEmployeeNumber(int emplyeeNumber);
		int GetEmployeeNumber() const;

		void SetSalary(int newSalary);
		int GetSalary() const;

		bool GetIsHired() const;
	};
}