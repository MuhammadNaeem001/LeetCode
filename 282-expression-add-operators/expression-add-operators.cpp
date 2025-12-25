class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string path;
        dfs(num, target, 0, 0LL, 0LL, path, ans);
        return ans;
    }

private:
    void dfs(const string& num, long long target, int i,
             long long evalVal, long long prev,
             string& path, vector<string>& ans) {
        const int n = (int)num.size();
        if (i == n) {
            if (evalVal == target) ans.push_back(path);
            return;
        }

        for (int j = i; j < n; j++) {
            // No leading zeros
            if (j > i && num[i] == '0') break;

            string s = num.substr(i, j - i + 1);
            long long cur = stoll(s);

            int oldLen = (int)path.size();

            if (i == 0) {
                // first number, no operator
                path += s;
                dfs(num, target, j + 1, cur, cur, path, ans);
                path.resize(oldLen);
            } else {
                path += '+';
                path += s;
                dfs(num, target, j + 1, evalVal + cur, cur, path, ans);
                path.resize(oldLen);

                path += '-';
                path += s;
                dfs(num, target, j + 1, evalVal - cur, -cur, path, ans);
                path.resize(oldLen);

                path += '*';
                path += s;
                // fix precedence for multiplication
                dfs(num, target, j + 1, evalVal - prev + prev * cur, prev * cur, path, ans);
                path.resize(oldLen);
            }
        }
    }
};
