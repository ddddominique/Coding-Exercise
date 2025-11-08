class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '*') {
                st.pop();
            } else {
            st.push(c);
            }

        }
        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};