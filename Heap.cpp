/*堆排序
先构建堆 
	如果要从小到大排序则构建大根堆 
	如果要从大到小排序，则要小根堆
从最后一个节点的父节点开始进行heapfy（不断更新每个节点的位置）

构建好堆以后，进行堆排序；
交换堆顶元素和最后一个元素，再进行构建堆（堆的元素个数减一 不断循环）
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define max_size 20
#define max_num 50

void swap(vector<int>& ans, int i, int j) {
	ans[i] = ans[i] ^ ans[j];
	ans[j] = ans[i] ^ ans[j];
	ans[i] = ans[i] ^ ans[j];
}

void heapfy(vector<int>& tree,int n,int i) {//更新堆的父子节点 使其满足堆的规则
	if (i >= n) {
		return;
	}
	int max = i, left = 2 * i + 1, right = 2 * i + 2;
	if (left<n && tree[left] > tree[max]) {
		max = left;
	}
	if (right<n && tree[right] > tree[max]) {
		max = right;
	}
	if (i != max) {
		swap(tree,i, max);
		heapfy(tree, n, max);
	}
}

void build_heap(vector<int>& tree, int n) {//构建堆
	int last = n - 1;
	int parent = (last - 1) / 2;
	for (int i = parent; i >= 0; --i) {
		heapfy(tree, n,i);
	}
}

void heap_sort(vector<int>& tree, int n) {//堆排序
	build_heap(tree, n);
	for (int i = n-1; i > 0; --i) {
		swap(tree, i, 0);
		heapfy(tree, i, 0);
	}
}

int main()
{
	vector<int>tree(max_size,0);//创建数组并进行赋值 并进行打印
	for (int i = 0; i < max_size; ++i) {
		//srand(time(0));
		tree[i] = rand() % max_num + 1;
	}
	cout << "堆排序以前：" << endl;
	for (int num : tree) {
		cout << num << "  ";
	}cout << endl;

	//堆排序  并打印
	heap_sort(tree, max_size);

	cout << "堆排序以后：" << endl;
	for (int num : tree) {
		cout << num << "  ";
	}cout << endl;

	return 0;
}