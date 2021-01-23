#include <iostream>
#include <string>
using namespace std;

// �׻� �������� ������ �Ϲ����� ��� ������ �۵��ϴ� ������ ������ ���ڿ� ��Ī �˰����̴�.
// �ؽø� �̿���.
// ��¡�ϴ� �����͸� �ٲپ� ó����. ���� ���� �ӵ� O(1)

// �ؽð��� ���� �� �����÷μ��� �߻��ص� �Ϲ����� CPU�� ��� ������ �������� ���� ��ȣȭ ���� ��ȣ�� �Դٰ��� �ϹǷ� �ؽ� ���� ��ġ�ϴ� ��. �� �������� ���α׷��� �ۼ��ϰ��� �ϸ� ������ ������ �̿�(MOD)����.


// parent : Ư���� �� ��, pattern : ��� ���� ���ڿ��� ����
// �� ã�´�.
void FindString(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int parentHash = 0, patternHash = 0, power = 1;

	// ��ü ��ġ���� �� �ϳ��� �˻��ϱ�
	for (int i = 0; i <= parentSize - patternSize; ++i) {
		if (i == 0) { // i�� 0�ϰ�� �ؽ����� ���� �� �ֵ��� ������ (�ʱ�ȭ ��)
			for (int j = 0; j < patternSize; ++j) { 
				parentHash += parent[patternSize - 1 - j] * power; // (�� ��) ���� ������ ��ġ(������)����  �������� ���� ������.
				patternHash += pattern[patternSize - 1 - j] * power; // (����) ���� �ؽ��� ���� ������ ������.
				if (j < patternSize - 1) // power�� 2�� ����ؼ� ���Ѵ�.
					power <<= 1;
			}
		}
		else {
			//�տ������� �ڷ� �� �����鼭 ���� ���ϱ� ���� 
			// �� �� �ؽ� �� = 2 * (�� �� �ؽ� �� - ���� �տ� �ִ� ������ ��ġ) + ���Ӱ� ���� ������ ��ġ
			parentHash = 2 * (parentHash - parent[i - 1] * power) + parent[patternSize - 1 + i];
		}

		// �� ���忡���� �ؽð��� ã�� ������ �ؽð��� ��ġ�ϸ�
		if (parentHash == patternHash) {
			bool finded = true;
			for (int j = 0; j < patternSize; ++j) { // ��Ȯ�� ��ġ�ϴ��� Ȯ��
				// ��� ���ڿ��� �˻���.
				if (parent[i + j] != pattern[j]) {
					finded = false; // �������� ������
					break;
				}
			}

			// ���ڿ��� ã������
			if (finded) {
				cout << i + 1 << "��°���� �߰���.\n";
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	FindString(parent, pattern);

	return 0;
}