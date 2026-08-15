class Solution {
public:
    string addBinary(string a, string b) {
        int length_a = a.length() - 1;
        int length_b = b.length() - 1;
        int carryover = 0;
        string result;
        while (length_a >= 0 || length_b >= 0 || carryover == 1) {
            if (length_a >= 0) {
                carryover += a[length_a--] - '0';
            }
            if (length_b >= 0) {
                carryover += b[length_b--] - '0';
            }
            result += carryover % 2 + '0';
            carryover /= 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};