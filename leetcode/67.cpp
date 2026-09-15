class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<int>> map;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            map[s].push_back(i);
        }
        for (auto& hold : map) {
            vector<string> mystrings;
            for (int j : hold.second) {
                mystrings.push_back(strs[j]);
            }
            result.push_back(mystrings);
        }
        return result;

    }
};