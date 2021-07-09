// Strategy Pattern
// 옵션들마다의 행동들을 모듈화해서 독립적이고 상호 교체 가능하게 만드는것
// 어떤 동일한 틀 안에 있는 특정 작업의 방식, 모드를 바꿔줄 때 사용.
#include <iostream>
using namespace std;

enum class E_Mode {
	All,
	Image,
	News,
	Map
};

// Interface
class SearchStrategy {
public:
	virtual void Search() = 0;
};


class MyProgram;
class SearchButton {
private:
	MyProgram* m_pMyProgram;
	SearchStrategy* m_pSearchStrategy;
public:
	void OnClick() {
		m_pSearchStrategy->Search();
	}
	

public:
	SearchButton() : 
		m_pMyProgram(nullptr),
		m_pSearchStrategy(nullptr) {
	}
	SearchButton(MyProgram* _pMyProgram) {
		m_pMyProgram= _pMyProgram;
	}
	~SearchButton() {}
};

class MyProgram {
public:
	SearchButton* m_pSearchBtn;
	E_Mode m_eMode;

	void SetModeAll() { m_eMode = E_Mode::All; }
	void SetModeImage() { m_eMode = E_Mode::Image; }
	void SetModeNews() { m_eMode = E_Mode::News; }
	void SetModeMap() { m_eMode = E_Mode::Map; }

	MyProgram() :
		m_pSearchBtn(nullptr),
		m_eMode(E_Mode::All) {
		m_pSearchBtn = new SearchButton;
	}
};


class SearchStrategyAll : public SearchStrategy {
public:
	virtual void Search() override {
		cout << "SearchStrategyAll \n";
	};
};

class SearchStrategyImage : public SearchStrategy {
public:
	virtual void Search() override {
		cout << "SearchStrategyImage \n";
	};
};

class SearchStrategyNews : public SearchStrategy {
public:
	virtual void Search() override {
		cout << "SearchStrategyNews \n";
	};
};
class SearchStrategyMap : public SearchStrategy {
public:
	virtual void Search() override {
		cout << "SearchStrategyMap \n";
	};
};


int main() {
	MyProgram program;
	
	return 0;
}