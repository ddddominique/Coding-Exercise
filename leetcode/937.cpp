class Solution {
    struct Log {
        string identifier;
        string words;
        bool isDigit;
        string original;
    };
    Log parse(string s) {
        istringstream iss(s);
        string identifier;
        string words;

        iss >> identifier;
        getline(iss >> ws, words);
        bool isDigit = isdigit(words[0]);
        return {identifier, words, isDigit, s};
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<Log> Logs;
        for (string s : logs) {
            Logs.push_back(parse(s));
        }

        stable_sort(Logs.begin(), Logs.end(), 
        [](const Log& a, const Log& b) {
            // the return value answers should a come before b
            // both are letter logs
            if (!a.isDigit && !b.isDigit) {
                if (a.words != b.words) {
                    return a.words < b.words;
                }
                return a.identifier < b.identifier;
            }
            // a i sletter, b is digit
            if (!a.isDigit && b.isDigit) {
                return true;
            }
            // a is digit, b i sletter
            if (a.isDigit && !b.isDigit) {
                return false;
            }
            return false;
        });
        vector<string> result;
        for (Log& log : Logs) {
            result.push_back(log.original);
        }
        return result;
    }
};