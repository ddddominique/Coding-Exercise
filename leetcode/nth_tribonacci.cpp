class Solution {
public:
    int tribonacci(int n) {
        int t0 = 0, t1 = 1;
        if (n <= 1) {return n;}
        int t2 = 1;
        if (n == 2) {return t2;}
        int t3;
        for (int i = 3; i <=n ; ++i) {
            t3 = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = t3;
        }
        return t3;
    }
};