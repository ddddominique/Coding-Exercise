class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int length1 = word1.length();
        int length2 = word2.length();
        int index1 = 0;
        int index2 = 0;
        string result = "";
        while (length1 > 0 || length2 > 0) {
            if (length1 > 0) {
                result += word1[index1];
                index1++;
                length1--;
            }
            if (length2 > 0) {
                result += word2[index2];
                index2++;
                length2--;
            }
        }
        return result;
    }
};