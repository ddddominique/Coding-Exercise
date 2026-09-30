
class Solution {
public:
    struct Transaction {
        string name;
        int time;
        int amount;
        string city;
    };

    Transaction parse(string s) {
        stringstream ss(s);
        string name,  time, amount, city;
        getline(ss, name, ',');
        getline(ss, time,',');
        getline(ss, amount, ',');
        getline(ss, city, ',');
        return {name, stoi(time), stoi(amount), city};
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        // name, time, amount, city
        // alice, 20,  8000,   mtv
        int n = transactions.size();
        vector<Transaction> t;
        vector<bool> invalid(n, false);
        // parse
        for (string s : transactions) {
            t.push_back(parse(s));
        }
        // rule1: amount > 1000
        for (int i = 0; i < n; ++i) {
            if (t[i].amount > 1000) {
                invalid[i] = true;
            }
        }
        // rule2: same name, different city, within 60 seconds
        for (int i = 0; i <n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (t[i].name == t[j].name && abs(t[i].time - t[j].time) <= 60 && t[i].city != t[j].city) {
                    invalid[i] = true;
                    invalid[j] = true;
                }
            }
        }
        vector<string> result;
        for (int i = 0; i < n; ++i) {
            if (invalid[i]) {
                result.push_back(transactions[i]);
            }
        }
        return result;

    }
};