class Solution {

public:
    static bool mycompare(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // trucksize = max number of boxes on the truck
        // [number of boxes, number of unit per box]
        // 50 + 27 + 14
        sort(boxTypes.begin(), boxTypes.end(), mycompare);
        int result = 0;
        for (auto& pair : boxTypes) {
            int take = min(truckSize, pair[0]);
            result += take * pair[1];
            truckSize -= take;
            if (truckSize == 0) break;
        }
        return result;
    }
};