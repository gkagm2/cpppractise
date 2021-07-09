#include <iostream>
using namespace std;

// Singleton
class Settings {
private:
	static Settings* m_pSettings;

public:
	static void Function() {
		cout << "settings function\n";
	}
public:
	static Settings* GetInstance() {
		if (nullptr == m_pSettings)
			m_pSettings = new Settings;
		return m_pSettings;
	}

public:
	Settings() {}
	~Settings() {
		if (m_pSettings)
			delete m_pSettings;
	}
}; 
Settings* Settings::m_pSettings = nullptr;


int main() {
	Settings::Function();
	return 0;
}

