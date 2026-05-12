class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<int>> mymap;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mymap[s].push_back(i);
        }
        int count = 0;
        result.resize(mymap.size());
        for (auto item : mymap) {

            for (int i : item.second) {
                result[count].push_back(strs[i]);
            }
            count += 1;
        }
        return result;
    }
};
