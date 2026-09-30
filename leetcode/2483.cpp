class Solution {
public:
    int bestClosingTime(string customers) {
        // Y Y N Y
        // prefix of N + suffix of Y
        int n = customers.length();
        vector<int> myprefix(n + 1, 0);
        vector<int> mysuffix(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            // 1 2 3 4 
            myprefix[i] = myprefix[i - 1] + (customers[i - 1] == 'N');
        }
        for (int i = n - 1; i >= 0; --i) {
            // 3 2 1 0
            mysuffix[i] = mysuffix[i + 1] + (customers[i] == 'Y');
        }
        int smallest = INT_MAX; 
        int result = 0;       
        for (int i = 0; i <= n; ++i) {
            int penalty = myprefix[i] + mysuffix[i];
            if (penalty < smallest) {
                smallest = penalty;
                result = i;
            }
        }

        return result;
    }
};