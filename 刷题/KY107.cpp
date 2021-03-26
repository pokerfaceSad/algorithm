# include <iostream>
# include <climits>
# include <cstring>
# include <cmath>
# include <set>
# include <vector>
using namespace std;

const int maxn = 105;
const int maxm = 500;
int N, M; // N个城市 M条道路
const int inf = INT_MAX/10;
int net[maxn][maxn];
set<int> visited;
set<int> unvisted;
int length[maxn];

void getReachableNodes(int node, vector<int>& reachableNodes) {
    reachableNodes.clear();
    for (int i = 0 ; i < N ; i++) {
        if (net[node][i] != 0) reachableNodes.push_back(i);
    }
}

void relaxationOperate(int node, vector<int>& reachableNodes) {
    for (auto reachableNode : reachableNodes) {
        if (length[reachableNode] > length[node] + net[node][reachableNode]) {
            length[reachableNode] = length[node] + net[node][reachableNode];
        }
    }
}

int getNearestNode() {
    int NearestNode = *(unvisted.begin());
    for (auto node : unvisted) {
        if (length[node] < length[NearestNode]) {
            NearestNode = node;
        }
    }
    return NearestNode;
}

int main() {
    
    cin >> N >> M;
    // 初始化矩阵
    memset(net, 0, sizeof(net));
    int from, to;
    for (int i = 0 ; i < M ; i++) {
        cin >> from >> to;
        net[from][to] = pow(2, i);
        net[to][from] = net[from][to];
    }
    // for (int i = 0 ; i < N ; i++) {
    //     for (int j = 0 ; j < N ; j++) {
    //         cout << net[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int node = 0;
    // 初始化length中的值为无穷大
    memset(length, inf, sizeof(length));
    for (int i = 0 ; i < N ; i++) {
        unvisted.insert(i);
    }
    unvisted.erase(unvisted.find(node));
    visited.insert(node);
    length[node] = 0;

    vector<int> reachableNodes;
    int nearestNode;

    while (!unvisted.empty()) {
        getReachableNodes(node, reachableNodes);
        relaxationOperate(node, reachableNodes);
        nearestNode = getNearestNode();
       
        unvisted.erase(unvisted.find(nearestNode));
        visited.insert(nearestNode);
        node = nearestNode;
    }
    cout << length[N-1] << endl;
    return 0;
}

