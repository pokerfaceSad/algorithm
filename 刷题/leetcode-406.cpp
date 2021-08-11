# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        vector<vector<int>> ans;
        for (int i = 0 ; i < people.size() ; i++) {
            ans.insert(ans.begin() + people[i][1], people[i]);
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    Solution s;
    auto res = s.reconstructQueue(people);
    for (auto peo : res) {
        cout << peo[0] << "-" << peo[1] << " ";
    }
    cout << endl;
    return 0;
}