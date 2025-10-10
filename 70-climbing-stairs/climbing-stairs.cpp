class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int a = 1, b = 2, c = 0;

        for (int i = 3; i <= n; i++) {
            c = a + b;  // number of ways to reach current step
            a = b;      // move forward
            b = c;
        }

        return b;
    }
};
