#include <iostream>
#include <memory> // ����Ʈ �����͸� �̿��Ϸ��� �� ��������� �ʿ��Ѵ�.
using namespace std;

struct Student {
	char name[10];
	int age;
};

int main() {
	// ����Ʈ �������� ������ 3�������� �ִ�.

	// 1. unique_ptr
	std::unique_ptr<Student> uniq; // �������ϰ� �ִ� ��ü�� ���� �ܵ����� ���ʽ��� ������.  ���ܻ�Ȳ�� �߻����� �� �޸� ������ �ܼ��ϰ� �� �� �ִ�.

	/* �ٸ� ����� ���� ��� */
	Student *pStudent = new Student();
	auto u = make_unique<Student>(); // C++14 �������� ����
	std::unique_ptr<Student> pu(new Student);

	// 2. shared_ptr
	std::shared_ptr<Student> shar; // �����Ϳ� ���� ���ʽ��� ���� ���� �л�� �� �ְ� ���ش�. shar ������ �ٸ� ������ ���Ե� ������ ���۷��� ī���Ͱ� �����Ǿ� �������� ���ʰ� �ϳ� �� �þ��ٴ� ���� ǥ���Ѵ�.
	// ��� �������� ��� ���� ���۷��� ī���Ͱ� 0�̵ǹǷ� �̴� ���ʰ� �� �̻� ���ٴ� ���̹Ƿ� �����Ϳ� ���� �����ǰ� �ִ� ��ü�� �޸𸮰� �����ȴ�. �迭����X
	
	auto s = make_shared<Student>();
	std::shared_ptr<Student> ps(new Student);

	// 3. weak_ptr
	std::weak_ptr<Student> weak; // shared_ptr�� ���Ե� ��ü�� �����ϵ� ���۷��� ī���Ϳ� ������ �ְ� ���� ���� �� ����Ѵ�.


	// �迭�� �������� ���� (array�� vector�� ���� STL �����̳ʸ� �̿��ϴ°� �� ����)
	auto myVariableSizedArray = make_unique<int[]>(10);
	for (int i = 0; i < 10; ++i) {
		myVariableSizedArray[i] = i;
		cout << myVariableSizedArray[i] << "\n";
	}


	return 0;
}