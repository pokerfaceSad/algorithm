# include <iostream>
# include <sstream>
# include <stack>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        istringstream input(s);
        stack<string> stk;
        string str;
        while (input >> str) stk.push(str);
        ostringstream output;
        while (!stk.empty()) {
            output << stk.top(); stk.pop();
            if (!stk.empty()) output << " ";
        }
        return output.str();
        
    }
};

int main() {
    istringstream input("     asdas asdasd      ");
    string str;
    
    while (input >> str) cout << str << "-----" << endl;
}