# include <iostream>
# include <vector>
# include <climits>
# include <algorithm>
# include <queue>
using namespace std;

struct NodeInfo {
    int nodeNo;
    int distance;
    NodeInfo(int _nodeNo, int _distance) : nodeNo(_nodeNo), distance(_distance) {};
};

struct cmp
{
    bool operator()(NodeInfo a, NodeInfo b) {
        return a.distance > b.distance;
    }
};


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // return dijsktra_enum(times, n, k);
        return dijsktra_heap(times, n, k);
    }
    int dijsktra_heap(vector<vector<int>>& times, int n, int k) {
        int INF = INT_MAX / 2;
        vector<int> distance(n, INF);
        vector<vector<int>> matrix(n, vector<int>(n, INF));
        for (auto time : times) matrix[time[0]-1][time[1]-1] = time[2];
        distance[k-1] = 0;
        priority_queue<NodeInfo, vector<NodeInfo>, cmp> q; // cmp为true则元素优先级更低
        q.push(NodeInfo(k-1, 0));
        while (!q.empty()) {
            NodeInfo curNodeInfo = q.top(); q.pop();
            // 如果堆顶节点distance已经被更新，则该元素作废，直接跳过
            if (curNodeInfo.distance > distance[curNodeInfo.nodeNo]) continue;
            for (int y = 0 ; y < n ; y++) {
                if (matrix[curNodeInfo.nodeNo][y] + distance[curNodeInfo.nodeNo] < distance[y]) {
                    distance[y] = matrix[curNodeInfo.nodeNo][y] + distance[curNodeInfo.nodeNo];
                    // 已经找到最短路的节点不会被更新distance，因此也不会被重复加入队列
                    q.push(NodeInfo(y, distance[y]));
                }
            }
        }
        int ans = *max_element(distance.begin(), distance.end());
        return ans == INF ? -1 : ans;
    }

    int dijsktra_enum(vector<vector<int>>& times, int n, int k) {
        int INF = INT_MAX / 2;
        vector<int> visited(n, 0);
        vector<int> distance(n, INF);
        vector<vector<int>> matrix(n, vector<int>(n, INF));
        for (auto time:times) matrix[time[0]-1][time[1]-1] = time[2];
        distance[k-1] = 0;
        // visited[k-1] = 1;
        for (int i = 0 ; i < n ; i++) {
            // 找到未寻访节点中离源节点最近的节点
            int x = -1;
            for (int y = 0 ; y < n ; y++) {
                if (visited[y] == 0 && (x == -1 || distance[x] > distance[y])) x = y;
            }
            // 更新离源节点所有邻节点的distance
            for (int y = 0 ; y < n ; y++) {
                distance[y] = min(distance[y], distance[x] + matrix[x][y]);
            }
            visited[x] = 1;
        }
        int ans = *max_element(distance.begin(), distance.end());
        return ans == INF ? -1 : ans;
    }
};

int main() {
    vector<vector<int>> times = {{1,2,3}};
    int n = 2;
    int k = 1;
    Solution s;
    cout << s.networkDelayTime(times, n, k) << endl;
    return 0;
}