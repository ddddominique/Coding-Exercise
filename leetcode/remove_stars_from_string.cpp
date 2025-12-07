class Solution {
public:
    string removeStars(string s) {
        stack<char> mystack;
        for (char c : s) {
            if (c == '*') {
                mystack.pop();
            } else {
                mystack.push(c);
            }

        }
        string result;
        while (!mystack.empty()) {
            result.push_back(mystack.top());
            mystack.pop();
        }
        reverse(result.begin(), result.end());
        return result;

    }
};