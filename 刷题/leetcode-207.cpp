# include <iostream>
# include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> adjacencyList; // 邻接表
    vector<int> states; // 状态表 0 未遍历 -1 正在遍历 1 完成遍历
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adjacencyList.resize(numCourses);
        states.resize(numCourses);
        // 构建邻接表
        for (auto info:prerequisites) {
            adjacencyList[info[1]].push_back(info[0]);
        }
        // 初始化states
        for (int i = 0 ; i < numCourses; i++) {
            states[i] = 0;
        }
        for (int i = 0 ; i < numCourses ; i++) {
            if (!dfs(i)) return false;
        }
        return true;

    }

    bool dfs(int node) {
        if (states[node] == 1) return true;
        if (states[node] == -1) return false;
        states[node] = -1;
        for (int i = 0 ; i < adjacencyList[node].size() ; i++) {
            if(!dfs(adjacencyList[node][i])) return false;
        }
        states[node] = 1;
        return true;
    }
};

int main() {
    vector<vector<int>> pre = {{0,1}, {1,0}};
    int num = 2;
    Solution s;
    cout << s.canFinish(num, pre) << endl;
    return 0;
}