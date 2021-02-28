# include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 0 ; i < n-1 ; i++) {
            str = recurse(str);
        }
        return str;
    }
    string recurse(string current) {
        char current_num = current[0];
        int current_count = 0;
        string res = "";
        for (int i = 0 ; i < current.size() ; i++) {
            if (current[i] == current_num) {
                current_count++;
                continue;
            } else {
                res += (current_count + '0');
                res += current_num;
                current_num = current[i];
                current_count = 1;
            }
        }
        res += (current_count + '0');
        res += current_num;
        return res;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(4) << endl;
    return 0;
}