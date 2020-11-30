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
/* using을 사용하지 않았을 때 

// 생성자일 경우
Spreadsheet::SpreadsheetCell::SpreadsheetCell() : mValue(0) { }

// 클래스 안의 클래스를 리턴할 경우
Spreadsheet::SpreadsheetCell& Spreadsheet::getCellAt(int x, int y) {

}
*/
//////////////////////////////////
// using을 사용했을 때

// using을 사용할 때
using Scell = Spreadsheet::SpreadsheetCell;

// 생성자일 경우
Scell::SpreadsheetCell() : mValue(0) { }

//////////////////////////////////
int main() {


	return 0;
}