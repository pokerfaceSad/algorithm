# include <vector>
# include <iostream>
# include <queue>
using namespace std;

class Solution {
private:
    vector<vector<int>> adjancencyList;
    vector<int> inDeg; // 节点入度表
    vector<int> res;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        adjancencyList.resize(numCourses);
        inDeg.resize(numCourses);
        for (int i = 0 ; i < numCourses ; i++) inDeg[i] = 0;
        for (auto info : prerequisites) {
            adjancencyList[info[1]].push_back(info[0]);
            inDeg[info[0]]++;
        }
        for (int i = 0 ; i < numCourses ; i++) {
            if (inDeg[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int curNode = q.front();
            res.push_back(curNode); q.pop();
            for (int i = 0 ; i < adjancencyList[curNode].size(); i++) {
                if (--inDeg[adjancencyList[curNode][i]] == 0)
                    q.push(adjancencyList[curNode][i]);
            }
            
        }
        return res.size() == numCourses ? res : vector<int>();
    }
};

int main() {
    vector<vector<int>> pre = {{0,1}, {1,0}};
    int num = 3;
    Solution s;
    auto res = s.findOrder(num, pre);
    for (auto r : res) {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}