class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> results;
        for (int spell: spells) {
            long long need = ceil((double)success/spell);
            auto hold = lower_bound(potions.begin(), potions.end(), need);
            int result;
            if (hold == potions.end()) {result = 0;}
            else {result = potions.size() - (hold - potions.begin());}
            results.push_back(result);
        }
        return results;
    }
};