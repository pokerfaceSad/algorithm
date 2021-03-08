# include <iostream>
# include <vector>
# include <map>
using namespace std;

class Solution {
    map<int, string> mappings = {
        {3, "Fizz"},
        {5, "Buzz"}
    };
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1 ; i <= n ; i++) {
            string str = "";
            for (auto mapping : mappings) {
                if (i % mapping.first == 0) {
                    str += mapping.second;
                }
            }
            if (str == "") {
               str += to_string(i);
            }
            res.push_back(str);
        }
        return res;

    }
};

int main() {
    return 0;
}