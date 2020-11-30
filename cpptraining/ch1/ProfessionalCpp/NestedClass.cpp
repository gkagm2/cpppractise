#include <iostream>

int kMaxWidth = 500;
int kMaxHeight = 500;


class SpreadsheetApplication {
};

class Spreadsheet {
	
public:
	class SpreadsheetCell {
		
	public:
		SpreadsheetCell();
		SpreadsheetCell(double initialValue);
	private:
		double mValue;
		std::string mString;
		mutable int mNumAccresses = 0;
	};
	Spreadsheet(const SpreadsheetApplication& theApp, int inWidth = kMaxWidth, int inHeight = kMaxHeight);
	Spreadsheet(const Spreadsheet& src);
	~Spreadsheet();

public:
	SpreadsheetCell& getCellAt(int x, int y);
};

///////////////////////////////////
/* using�� ������� �ʾ��� �� 

// �������� ���
Spreadsheet::SpreadsheetCell::SpreadsheetCell() : mValue(0) { }

// Ŭ���� ���� Ŭ������ ������ ���
Spreadsheet::SpreadsheetCell& Spreadsheet::getCellAt(int x, int y) {

}
*/
//////////////////////////////////
// using�� ������� ��

// using�� ����� ��
using Scell = Spreadsheet::SpreadsheetCell;

// �������� ���
Scell::SpreadsheetCell() : mValue(0) { }

//////////////////////////////////
int main() {


	return 0;
}