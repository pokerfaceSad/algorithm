# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> adjacencyList;
    vector<int> states;
    vector<int> res;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adjacencyList.resize(numCourses);
        states.resize(numCourses);
        
        for (int i = 0 ; i < numCourses ; i++) states[i] = 0;
        for (auto info : prerequisites) adjacencyList[info[1]].push_back(info[0]);
        
        for (int i = 0 ; i < numCourses ; i++) {
            if (!dfs(i)) return {};
        }
        // reverse
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(int node) {
        if (states[node] == 1) return true;
        if (states[node] == -1) return false;
        states[node] = -1;
        
        for (int i = 0 ; i < adjacencyList[node].size() ; i++) {
            if (!dfs(adjacencyList[node][i])) return false;
        }

        states[node] = 1;
        res.push_back(node);
        return true;
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