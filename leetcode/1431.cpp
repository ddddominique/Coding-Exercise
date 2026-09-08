class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int biggest = candies[0];
        for (int cand : candies) {
            if (cand > biggest) {
                biggest = cand;
            }
        }
        vector<bool> result(candies.size(), false);
        for (int i = 0; i < candies.size(); ++i) {
            if (candies[i] + extraCandies >= biggest) {
                result[i] = true;
            }
        }
        return result;

    }
};