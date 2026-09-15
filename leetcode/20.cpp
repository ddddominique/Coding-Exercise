class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                mystack.push(c);
            } else {
                if (mystack.empty()) return false;
                char mychar = mystack.top();
                if ( c == ')') {
                    if (mychar != '(') return false;
                } else if (c == ']') {
                    if (mychar != '[') return false;
                } else {
                    if (mychar != '{') return false;
                }
                mystack.pop();
            }
        }
        return mystack.empty();
    }
};