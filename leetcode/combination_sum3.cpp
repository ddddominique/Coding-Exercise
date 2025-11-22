class Solution {
    int fact(int n) {
        if (n == 0) {return 1;}
        return n * fact(n-1);
    }
    int sum(vector<int>& v) {
        int sum = 0;
        for (int x : v) {
            sum += x;
        }
        return sum;
    }

    vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> curr;
        int i = 0;
        int start = 0;
        dosmth(k, n, curr, i, start + 1);
        return result;

    }
    void dosmth(int k, int n, vector<int> curr, int i, int start) {
        if (i == k && sum(curr) == n) {
            result.push_back(curr);
            return;
        }

        for (int j = start; j <= 9; ++j) {
            curr.push_back(j);
            if (sum(curr) <= n) {
                dosmth(k, n, curr, i + 1, j + 1);
            }
            curr.pop_back();
        }
    }
};
