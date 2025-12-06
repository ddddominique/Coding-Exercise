class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for ( int i : arr) {
            freq[i] += 1;
        }
        unordered_set<int> occur;
        for (auto occ : freq) {
            occur.insert(occ.second);
        }

        return freq.size() == occur.size();
    } 
};

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int i : arr) {
            freq[i]++;
        }

        unordered_set<int> myv;
        for (auto my : freq) {
            if (myv.count(my.second)) return false;
            myv.insert(my.second);
        }

        return true;


    }
};