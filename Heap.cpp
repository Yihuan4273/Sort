/*������
�ȹ����� 
	���Ҫ��С���������򹹽������ 
	���Ҫ�Ӵ�С������ҪС����
�����һ���ڵ�ĸ��ڵ㿪ʼ����heapfy�����ϸ���ÿ���ڵ��λ�ã�

�����ö��Ժ󣬽��ж�����
�����Ѷ�Ԫ�غ����һ��Ԫ�أ��ٽ��й����ѣ��ѵ�Ԫ�ظ�����һ ����ѭ����
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

void heapfy(vector<int>& tree,int n,int i) {//���¶ѵĸ��ӽڵ� ʹ������ѵĹ���
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

void build_heap(vector<int>& tree, int n) {//������
	int last = n - 1;
	int parent = (last - 1) / 2;
	for (int i = parent; i >= 0; --i) {
		heapfy(tree, n,i);
	}
}

void heap_sort(vector<int>& tree, int n) {//������
	build_heap(tree, n);
	for (int i = n-1; i > 0; --i) {
		swap(tree, i, 0);
		heapfy(tree, i, 0);
	}
}

int main()
{
	vector<int>tree(max_size,0);//�������鲢���и�ֵ �����д�ӡ
	for (int i = 0; i < max_size; ++i) {
		//srand(time(0));
		tree[i] = rand() % max_num + 1;
	}
	cout << "��������ǰ��" << endl;
	for (int num : tree) {
		cout << num << "  ";
	}cout << endl;

	//������  ����ӡ
	heap_sort(tree, max_size);

	cout << "�������Ժ�" << endl;
	for (int num : tree) {
		cout << num << "  ";
	}cout << endl;

	return 0;
}