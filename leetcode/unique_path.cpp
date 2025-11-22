class Solution {
public:
    int uniquePaths(int m, int n) {
        long result = 1;
        int new_m = m + n - 2;
        int new_n = m - 1;
        for (int i = 1; i <= new_n; ++i) {
            result = result * (new_m - new_n + i)/i;
        }
        return int(result);
    }
};