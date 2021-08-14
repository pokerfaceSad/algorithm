/*
	迪杰斯特拉算法求最短路 
	
	将节点分为找到最短路（visited）和未找到最短路（unvisited）两个集合
	length数组存储各点距离出发点的距离 
	while(终点进入unvisited集合)
	{ 
		当前节点为首节点 
		从当前节点开始对图进行探索，找出当前节点所有的可达节点，对当前节点所有可达节点的length进行松弛操作
		找出unvisited中length最短的节点加入visited，并将该节点设为当前节点 
	}

*/
#include <iostream> 
#include <cstring> 
#include <vector>
#include <unordered_map>
using namespace std;

const int maxn = 5; //节点规模 
const int INF = 10000; //定义无穷大 

int net[maxn][maxn] =  {0,2,1,0,0,
						2,0,0,1,2,
						1,0,0,0,1,
						0,1,0,0,1,
						0,2,1,1,0}; //邻接矩阵 

int N = 5;
unordered_map<int, int> visited;
unordered_map<int, int> unvisited;
int fatherNode[maxn];

void dijkstra(int start) {
	visited[start] = 0;
	fatherNode[start] = -1;
	for (int i = 0 ; i < N ; i++) {
		if (i != start) unvisited[i] = INF;
	}
	int curNode = start;
	while (!unvisited.empty()) {
		// 对curNode的邻节点进行松弛操作
		for (int i = 0 ; i < N ; i++) {
			if (i == curNode || net[curNode][i] == 0 || visited.count(i)) continue;
			unvisited[i] = \
			visited[curNode] + net[curNode][i] > unvisited[i] ? \
			unvisited[i] : visited[curNode] + net[curNode][i];
		}
		// 找到未找到最短路集合中离起始点距离最近的节点，加入已找到最短路集合
		int node = -1, shortest = INF;
		for (auto node_info:unvisited) {
			if (node_info.second < shortest) {
				node = node_info.first;
				shortest = node_info.second;
			}
		}
		fatherNode[node] = curNode;
		unvisited.erase(node);
		visited[node] = shortest;
		curNode = node;
	}

	for (int node : fatherNode) {
		cout << node << " ";
	}
	cout << endl;
	for (int i = 0 ; i < N ; i++) {
		cout << visited[i] << " ";
	}
	cout << endl;
}

int main() {
	dijkstra(0);
	return 0;
}
