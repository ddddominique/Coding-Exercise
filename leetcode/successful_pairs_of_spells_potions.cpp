class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> result;
        int potion_size = potions.size();
        for (int spell : spells) {
            auto need = (success + spell - 1) / spell;
            auto hold = lower_bound(potions.begin(), potions.end(), need);
            int r;
            if (hold == potions.end()) {r = 0;}
            else {r = potion_size - (hold - potions.begin());}
            result.push_back(r);
        }
        return result;
    }
};