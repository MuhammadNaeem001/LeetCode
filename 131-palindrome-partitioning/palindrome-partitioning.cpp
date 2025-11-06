class Solution {
    vector<vector<string>> res;
    vector<string> path;
    bool isPal(const string &s, int l, int r) {
        while (l < r) if (s[l++] != s[r--]) return false;
        return true;
    }
    void backtrack(const string &s, int start) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (isPal(s, start, end)) {
                path.emplace_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }
};
