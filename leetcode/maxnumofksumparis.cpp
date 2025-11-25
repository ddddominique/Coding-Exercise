class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> freq;
        for (int num : nums) {
            int complement = k - num;
            if (freq.count(complement) && freq[complement]) {
                result += 1;
                freq[complement] -= 1;
            } else {
                freq[num] += 1;
            }
        }
        return result;
    }
};
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> s;
        int result = 0;
        for (int n : nums) {
            s[n]++;
        }
        for (int n : nums) {
            if (s[n]== 0) continue;
            int need = k - n;
            if (s[need] > 0) {
                if (need == n && s[need]< 2) continue;
                result++;
                s[need]--;
                s[n]--;
            }
        }
        return result;
    }
};

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int result = 0;
        while (left < right) {
            int ans = nums[left] + nums[right];
            if (ans == k) {
                result++;
                left++;
                right--;
            } else if (ans < k) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};
