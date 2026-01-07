class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int result = 0;
        for (int i = 0; i < citations.size(); ++i) {
            if (citations[i] >= citations.size() - i) {return citations[i];}
        }
        return 0;
    }
};