class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> t1;
        unordered_set<int> t2;
        for (int i = 0; i < nums1.size(); ++i) {
            t1.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); ++i) {
            t2.insert(nums2[i]);
        }
        vector<int> result1, result2;
        for (int i : t1) {
            if (!t2.count(i)) {
                result1.push_back(i);
            }
        }
        for (int i : t2) {
            if (!t1.count(i)) {
                result2.push_back(i);
            }
        }

        return {result1, result2};
    }
};

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result(2);
        unordered_set<int> mynum1;
        unordered_set<int> mynum2;
        for (int n : nums1) {
            mynum1.insert(n);
        }
        for (int n : nums2) {
            mynum2.insert(n);
        }

        for (int n : mynum1) {
            if (mynum2.count(n)) {
                continue;
            } else {
                result[0].push_back(n);
            }
        }

        for (int n : mynum2) {
            if (mynum1.count(n)) {
                continue;
            } else {
                result[1].push_back(n);
            }
        }
        return result;
    }
};