class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int read = 0, write = 0;

        while (read < n) {
            int count = 0;
            int curr_char = chars[read];
            while (read < n && chars[read] == curr_char) {
                count++;
                read++;
            }
            chars[write] = curr_char;
            write++;
            if (count > 1) {
                string mystr = to_string(count);
                for (char c : mystr) {
                    chars[write] = c;
                    write++;
                }
            }
        }
        return write;
    }
};
