class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp; // stores last index of each character
        int maxLen = 0;
        int start = 0; // left boundary of current window
        
        for (int end = 0; end < s.size(); end++) {
            char current = s[end];
            
            // If character already seen, move start pointer
            if (mp.find(current) != mp.end()) {
                start = max(start, mp[current] + 1);
            }
            
            // Update last seen index of current character
            mp[current] = end;
            
            // Calculate max length
            maxLen = max(maxLen, end - start + 1);
        }
        
        return maxLen;
    }
};
