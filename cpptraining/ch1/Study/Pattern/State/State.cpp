// Ư�� ���¸��� �ٸ��� �� ���� ���ư��� �� ���µ� ��ü�� �� ���¸��� ����� �� �ϰ� �Բ� �ϳ��ϳ� ���ȭ�ؼ� �����ص� �� ���δ�.
// ��带 ���� �״� �� �� ���
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