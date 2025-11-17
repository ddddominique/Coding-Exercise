class Solution {
    unordered_map<int, string> ump;
    vector<string> ans;
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {return ans;}
        ump[2] = "abc";
        ump[3] = "def";
        ump[4] = "ghi";
        ump[5] = "jkl";
        ump[6] = "mno";
        ump[7] = "pqrs";
        ump[8] = "tuv";
        ump[9] = "wxyz";

        string currString = "";
        dosmth(digits, currString, 0);
        return ans;
    }

    void dosmth(string digits, string currString, int i) {
        if (i == digits.size()) {
            ans.push_back(currString);
            return;
        }

        for (auto letter : ump[digits[i] - '0']) {
            currString.push_back(letter);
            dosmth(digits, currString, i+1);
            currString.pop_back();
        }
    }
};
