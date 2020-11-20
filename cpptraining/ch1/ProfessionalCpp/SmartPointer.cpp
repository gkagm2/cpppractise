#include <iostream>
#include <memory> // ����Ʈ �����͸� �̿��Ϸ��� �� ��������� �ʿ��Ѵ�.
using namespace std;

struct Student {
	char name[10];
	int age;
};

int main() {
	// ����Ʈ �������� ������ 3�������� �ִ�.

	// 1. uniqye_ptr
	std::unique_ptr<Student> uniq; // �������ϰ� �ִ� ��ü�� ���� �ܵ����� ���ʽ��� ������.  ���ܻ�Ȳ�� �߻����� �� �޸� ������ �ܼ��ϰ� �� �� �ִ�.

	/* �ٸ� ����� ���� ��� */
	Student *pStudent = new Student();
	auto u = make_unique<Student>(); // C++14 �������� ����
	std::unique_ptr<Student> student(new Student);

	// 2. shared_ptr
	std::shared_ptr<int> shar; // �����Ϳ� ���� ���ʽ��� ���� ���� �л�� �� �ְ� ���ش�. shar ������ �ٸ� ������ ���Ե� ������ ���۷��� ī���Ͱ� �����Ǿ� �������� ���ʰ� �ϳ� �� �þ��ٴ� ���� ǥ���Ѵ�.
	// ��� �������� ��� ���� ���۷��� ī���Ͱ� 0�̵ǹǷ� �̴� ���ʰ� �� �̻� ���ٴ� ���̹Ƿ� �����Ϳ� ���� �����ǰ� �ִ� ��ü�� �޸𸮰� �����ȴ�. �迭����X

	// 3. weak_ptr
	std::weak_ptr<int> weak; // shared_ptr�� ���Ե� ��ü�� �����ϵ� ���۷��� ī���Ϳ� ������ �ְ� ���� ���� �� ����Ѵ�.

	return 0;
}