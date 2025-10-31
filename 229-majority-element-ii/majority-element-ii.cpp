class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = 0, n2 = 1, c1 = 0, c2 = 0;
        for (int n : nums) {
            if (n == n1) c1++;
            else if (n == n2) c2++;
            else if (c1 == 0) { n1 = n; c1 = 1; }
            else if (c2 == 0) { n2 = n; c2 = 1; }
            else { c1--; c2--; }
        }

        c1 = c2 = 0;
        for (int n : nums) {
            if (n == n1) c1++;
            else if (n == n2) c2++;
        }

        vector<int> res;
        int limit = nums.size() / 3;
        if (c1 > limit) res.push_back(n1);
        if (c2 > limit) res.push_back(n2);
        return res;
    }
};
