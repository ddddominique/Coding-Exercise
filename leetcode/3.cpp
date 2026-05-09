class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        unordered_set<char> myset;
        int mymax = 1;
        int currmax = 1;
        int left = 0;
        myset.insert(s[0]);
        for (int right = 1; right < s.length(); ++right) {
            if (myset.count(s[right]) == 0) {
                myset.insert(s[right]);
            } else {
                while(myset.count(s[right])) {
                    myset.erase(s[left]);
                    left++;
                }
                myset.insert(s[right]);
            }
            currmax = right - left + 1;
            mymax = max(mymax, currmax);
        }
        return mymax;

    }
};
