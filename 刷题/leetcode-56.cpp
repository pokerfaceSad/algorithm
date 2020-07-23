# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

// 先排序再进行合并 可以简化操作
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> waitMergeIntervals = intervals;
        vector<vector<int>> mergedIntervals;
        vector<vector<int>> needMergeIntervals;
        for (auto waitMergeInterval : waitMergeIntervals) {
            needMergeIntervals.clear();
            int index = 0;
            vector<int> needDel;
            for (auto mergedInterval : mergedIntervals) {
                if (needMerge(waitMergeInterval, mergedInterval)) {
                    needMergeIntervals.push_back(mergedInterval);
                    needDel.push_back(index);
                }
                index++;
            }
            if (needMergeIntervals.empty()) {
                mergedIntervals.push_back(waitMergeInterval);
            } else {
                needMergeIntervals.push_back(waitMergeInterval);
                // 从后往前删 否则索引会出错
                for (int i = needDel.size() - 1 ; i >= 0; i--) {
                    mergedIntervals.erase(mergedIntervals.begin() + needDel[i]);
                }
                mergedIntervals.push_back(mergeIntervals(needMergeIntervals));
            }

        }

        return mergedIntervals;
    }
    bool needMerge(vector<int>& interval1, vector<int>& interval2) {
        if (interval1[0] > interval2[1] || interval2[0] > interval1[1]) return false;
        else return true;
    }

    vector<int> mergeIntervals(vector<vector<int>> intervals) {
        int low = intervals[0][0];
        int high = intervals[0][1];
        for (auto interval : intervals) {
            low = (low < interval[0] ? low : interval[0]);
            high = (high > interval[1] ? high : interval[1]);
        }
        vector<int> ret(2);
        ret[0] = low;
        ret[1] = high;
        return ret;
    }
};

int main() {
    vector<int> i1(2), i2(2), i3(2);
    i1[0] = 2;
    i1[1] = 3;
    i2[0] = 5;
    i2[1] = 7;
    i3[0] = 3;
    i3[1] = 5;
    vector<vector<int>> intervals(3);
    intervals[0] = i1;
    intervals[1] = i2;
    intervals[2] = i3;
    Solution s;
    // vector<int> ret = s.mergeIntervals(intervals);
    vector<vector<int>> ret = s.merge(intervals);

    for (auto v : ret) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    // for (auto i : ret) {
    //     cout << i << " ";
    // }
    // cout << intervals[0][0] << endl;
    return 0;
}