// Strategy Pattern
// �ɼǵ鸶���� �ൿ���� ���ȭ�ؼ� �������̰� ��ȣ ��ü �����ϰ� ����°�
// � ������ Ʋ �ȿ� �ִ� Ư�� �۾��� ���, ��带 �ٲ��� �� ���.
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