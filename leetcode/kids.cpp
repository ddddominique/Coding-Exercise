using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxval = *max_element(candies.begin(), candies.end());
        vector<bool> result(candies.size());  
        for (int i = 0; i < candies.size(); ++i) {
            if (candies[i] + extraCandies >= maxval) {
                result[i] = true;
            } else {
                result[i] = false;
            }
        }
        return result;
    }
};
