class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string hold = "";
        stack<string> mys;
        string result = "";
        while (iss >> hold) {
            mys.push(hold);
        }
        while (!mys.empty()) {
            result += mys.top();
            mys.pop();
            if (!mys.empty()) {
                result += " ";
            }
        }
        return result;
    }
};