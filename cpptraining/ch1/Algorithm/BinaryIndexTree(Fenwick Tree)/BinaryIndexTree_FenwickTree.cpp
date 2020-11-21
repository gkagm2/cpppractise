/*
참고 사이트
github - https://github.com/bluedawnstar/youtube/blob/master/algorithm_datastructure/range_query/binary_indexed_tree_range_add_and_sum.h
youtube - https://www.youtube.com/watch?v=_2DOKWvGets
*/

#include <iostream>
#include <vector>
using namespace std;

// BIT는 값을 한번에 1개씩만 업데이트 하기 때문에, 특정 범위 내에 값들에 값을 add	할 때는 O(kLogN)의 시간이 소요된다.
// BIT를 2개 사용 시 구간 업데이트는 O(logn)으로 처리할 수 있다.

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
		++pos; // BIT index는 1번부터 시작하므로 1을 더해준다.
		while (pos < tree.size()) { // 옮바른 범위 안에 있으면
			tree[pos] += num;
			pos += pos & -pos; // bit에서 최 하위 bit를 더해준다. (1이 있는 위치)
		}
	}

	// sum from 0 to pos, O(logN)
	int sum(int pos) const {
		int res = 0;

		++pos;
		while (pos > 0) { // pos가 0보다 큰동안
			res += tree[pos]; // tree의 pos위치에 있는 값을 결과값에 더해준다.
			pos &= pos - 1; // bit의 마지막 값이 1이 된 것을 지워준다.
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
	vector<int > value; // Update 할 값들을 저장할 vector
public:
	NumArray(vector<int> &nums) {
		int size = nums.size();
		bit.init(size);
		value.resize(size + 1);
		for (int i = 0; i < size; ++i) {
			value[i] = nums[i]; // 본래의 값을 저장한다.
			bit.add(i, nums[i]);
		}
	}
	
	// 기존값을 바꾸기
	void update(int i, int val) {
		bit.add(i, val - value[i]);  // 현재 있는 값을 빼줘야 한다.
		value[i] = val;
	}

	int sumRange(int i, int j) {
		return bit.sumRange(i, j);
	}
};

int main() {


	return 0;
}