// 특정 상태마다 다르게 할 일을 나아가서 그 상태들 자체를 그 상태마다 실행시 할 일과 함께 하나하나 모듈화해서 지정해둘 때 쓰인다.
// 모드를 껐다 켰다 할 때 사용
#include <iostream>
using namespace std;
class ModelSwitch;
class ModelStateDark;
class ModelState {
public:
	virtual void Toggle(ModelSwitch* _pModelSwitch) {};
	ModelState() {}
	~ModelState() {}
};

class ModelStateLight : public ModelState {
public:
	virtual void Toggle(ModelSwitch* _pModelSwitch) override {
		cout << "From light to dark\n";
		_pModelSwitch->SetState(new ModelStateDark);
	}

	ModelStateLight() {}
	~ModelStateLight() {}
};

class ModelStateDark : public ModelState {
public:
	virtual void Toggle(ModelSwitch* _pModelSwitch) override {
		cout << "From dark to light\n";
		_pModelSwitch->SetState(new ModelStateLight);
	}

	ModelStateDark() {}
	~ModelStateDark() {}
};
 
class ModelSwitch {
private:
	ModelState* m_pModelState;

public:
	void SetState(ModelState* _pModelState) {
		if (m_pModelState)
			delete m_pModelState;
		m_pModelState = _pModelState;
	}

public:
	ModelSwitch()  :
		m_pModelState(nullptr)
	{
		m_pModelState = new ModelStateLight();
	}
	~ModelSwitch() {}
};




int main() {

	return 0;
 }