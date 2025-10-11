class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string current;
        backtrack(s, 0, 0, current, result);
        return result;
    }

private:
    void backtrack(string& s, int index, int dots, string current, vector<string>& result) {
        // If we placed 3 dots and reached the end correctly
        if (dots == 3) {
            if (isValid(s.substr(index))) {
                current += s.substr(index);
                result.push_back(current);
            }
            return;
        }

        // Try all possible split points
        for (int len = 1; len <= 3 && index + len < s.size(); len++) {
            string part = s.substr(index, len);
            if (isValid(part)) {
                backtrack(s, index + len, dots + 1, current + part + ".", result);
            }
        }
    }

    bool isValid(string s) {
        // Must not be empty or too long
        if (s.empty() || s.size() > 3) return false;
        // No leading zero unless the number is exactly "0"
        if (s.size() > 1 && s[0] == '0') return false;
        // Must be between 0 and 255
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }
};
