class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> tCount, windowCount;
        for (char c : t) tCount[c]++;

        int have = 0, need = tCount.size();
        int left = 0, minLen = INT_MAX, start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            windowCount[c]++;

            if (tCount.count(c) && windowCount[c] == tCount[c])
                have++;

            while (have == need) {
                // update smallest window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // shrink window
                char leftChar = s[left];
                windowCount[leftChar]--;
                if (tCount.count(leftChar) && windowCount[leftChar] < tCount[leftChar])
                    have--;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
