class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // empty string is always segmentable

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // agar s[0..j-1] segmentable hai aur s[j..i-1] wordDict me milta hai
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break; // agar ek valid break mil gaya to aage check nahi karna
                }
            }
        }

        return dp[n];
    }
};

