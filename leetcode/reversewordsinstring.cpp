class Solution {
public:
    string reverseWords(string s) {
        string result;
        vector<string> mys;
        istringstream iss(s);
        string word;
        while (iss >> word) {
            mys.push_back(word);
        }
        for (int i = mys.size() - 1; i >= 0; --i) {
            result += mys[i];
            if (i != 0) {result += " ";}
        }
        return result;
    }
};