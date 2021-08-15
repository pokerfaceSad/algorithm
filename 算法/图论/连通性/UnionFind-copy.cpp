/*
	并查集判断网络连通性 
*/
#include<iostream> 
#include<set>
using namespace std;

const int maxn = 5;

int net[maxn][maxn] =  {0,0,0,0,0,
						0,0,0,1,2,
						0,0,0,0,1,
						0,1,0,0,1,
						0,2,1,1,0}; //邻接矩阵 

int pre[maxn];

int find(int node) {
	int root = node;
	while (pre[root] != root) {
		root = pre[root];
	}
	// 路经压缩 将路径中的所有节点挂到找到的root上
	int temp = node;
	while (pre[node] != root) {
		temp = pre[node];
		pre[node] = root;
		node = temp;
	}
	return root;
}

void join(int node1, int node2) {
	int r1 = find(node1), r2 = find(node2);
	pre[r1] = r2; // 将r1挂到r2下
}

int main() {
	// 初始化所有节点的前驱为自身
	for (int i = 0 ; i < maxn ; i++) {
		pre[i] = i;
	}
	// 遍历所有的边 无向图只遍历右上三角
	for (int i = 0 ; i < maxn ; i++) {
		for (int j = i+1 ; j < maxn ; j++) {
			if (net[i][j] != 0) join(i, j);
		}
	}
	set<int> rootSet;
	for (int i = 0 ; i < maxn ; i++) {
		cout << "root " << i << ":" << find(i) << endl;
		rootSet.insert(find(i));
	}

	cout << rootSet.size() << endl;
	return 0;
}
