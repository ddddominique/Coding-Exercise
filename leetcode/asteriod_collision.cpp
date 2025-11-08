class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i : asteroids) {
            bool alive = true;
            while (alive && !st.empty() && st.top() > 0 && i < 0) {
                if (abs(st.top()) > abs(i)) {
                    alive = false;
                } else if (abs(st.top()) == abs(i)) {
                    st.pop();
                    alive = false;
                } else {
                    st.pop();

                }
            }
            if (alive) st.push(i);
        }
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = (st.top());
            st.pop();
        }
        return result;
    }
};