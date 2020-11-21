/*
���� ����Ʈ
github - https://github.com/bluedawnstar/youtube/blob/master/algorithm_datastructure/range_query/binary_indexed_tree_range_add_and_sum.h
youtube - https://www.youtube.com/watch?v=_2DOKWvGets
*/

#include <iostream>
#include <vector>
using namespace std;

// BIT�� ���� �ѹ��� 1������ ������Ʈ �ϱ� ������, Ư�� ���� ���� ���鿡 ���� add	�� ���� O(kLogN)�� �ð��� �ҿ�ȴ�.
// BIT�� 2�� ��� �� ���� ������Ʈ�� O(logn)���� ó���� �� �ִ�.

struct BinaryIndexedTree {
	vector<int> tree;

	BinaryIndexedTree() {}

	BinaryIndexedTree(int n) {
		tree.resize(n + 1);
	}

	void init(int n) {
		tree.resize(n + 1);
	}

	// O(logN)
	void add(int pos, int num) {
		++pos; // BIT index�� 1������ �����ϹǷ� 1�� �����ش�.
		while (pos < tree.size()) { // �Źٸ� ���� �ȿ� ������
			tree[pos] += num;
			pos += pos & -pos; // bit���� �� ���� bit�� �����ش�. (1�� �ִ� ��ġ)
		}
	}

	// sum from 0 to pos, O(logN)
	int sum(int pos) const {
		int res = 0;

		++pos;
		while (pos > 0) { // pos�� 0���� ū����
			res += tree[pos]; // tree�� pos��ġ�� �ִ� ���� ������� �����ش�.
			pos &= pos - 1; // bit�� ������ ���� 1�� �� ���� �����ش�.
		}
		return res;
	}

	// inclusive, O(logN)
	int sumRange(int left, int right) const {
		int res = sum(right);
		if (left > 0)
			res -= sum(left - 1);
	}
};


// - for sum from 0 to pos
// - f(x) = mul * x + add
struct BinaryIndexedTreeMultAdd {
	BinaryIndexedTree bitMul;
	BinaryIndexedTree bitAdd;

	BinaryIndexedTreeMultAdd() {
	}

	explicit BinaryIndexedTreeMultAdd(int n) : bitMul(n), bitAdd(n) {
	}

	void init(int n) {
		bitMul.init(n);
		bitAdd.init(n);
	}

	void add(int x, int d) {
		bitMul.add(x, d);
		bitAdd.add(x, d * (1 - x));
	}

	// O(logn)
	void addRange(int left, int right, int d) {
		add(left, d);
		add(right + 1, -d);
	}

	// sum[0, x], O(logn)
	int sum(int x) const {
		return bitAdd.sum(x) + bitMul.sum(x) * x;
	}

	// sum[left, right], O(logn)
	int sumRange(int left, int right) const {
		return sum(right) - sum(left - 1);
	}
};

class NumArray {
private:
	BinaryIndexedTree bit;
	vector<int > value; // Update �� ������ ������ vector
public:
	NumArray(vector<int> &nums) {
		int size = nums.size();
		bit.init(size);
		value.resize(size + 1);
		for (int i = 0; i < size; ++i) {
			value[i] = nums[i]; // ������ ���� �����Ѵ�.
			bit.add(i, nums[i]);
		}
	}
	
	// �������� �ٲٱ�
	void update(int i, int val) {
		bit.add(i, val - value[i]);  // ���� �ִ� ���� ����� �Ѵ�.
		value[i] = val;
	}

	int sumRange(int i, int j) {
		return bit.sumRange(i, j);
	}
};

int main() {


	return 0;
}