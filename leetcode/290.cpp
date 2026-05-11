class Solution {

public:
    bool wordPattern(string pattern, string s) {
        vector<string> helper;
        istringstream iss(s);
        string hold;
        while (iss >> hold) {
            helper.push_back(hold);
        }
        if (pattern.length() != helper.size()) return false;
        unordered_map<char, string> mymap;
        unordered_map<string, char> mymap2;
        
        for(int i = 0; i < pattern.length(); ++i) {
            if (mymap.count(pattern[i]) && 
            mymap[pattern[i]] != helper[i]) return false;
            if (mymap2.count(helper[i]) && 
            mymap2[helper[i]] != pattern[i]) return false;
            mymap[pattern[i]] = helper[i];
            mymap2[helper[i]] = pattern[i];
        }
        return true;
    }
};
