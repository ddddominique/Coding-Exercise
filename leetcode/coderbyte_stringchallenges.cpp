#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int StringChallenge(string str) {
    unordered_map<char, vector<int>> map;
    for (int i = 0; i < str.size(); ++i) {
        map[str[i]].push_back(i);
    }

    int result = 0;
    for (auto& [key, vec] : map) {
        for (int i = 0; i < vec.size() - 1; ++i) {
            for (int j = i + 1; j < vec.size();++j) {
                string sub = str.substr(vec[i] + 1, vec[j] - vec[i] - 1);
                unordered_set<char> set(sub.begin(), sub.end());
                result = max(result, (int)set.size());
            }
        }
    }
    return result;
}
int main() {
    cout << StringChallenge("ahyjakh") << endl; // 3
}