class Solution {
public:
    int countDigitOne(int n) {
        long long res = 0;
        for (long long factor = 1; factor <= n; factor *= 10) {
            long long lower = n % factor;
            long long curr = (n / factor) % 10;
            long long higher = n / (factor * 10);
            
            if (curr == 0) res += higher * factor;
            else if (curr == 1) res += higher * factor + lower + 1;
            else res += (higher + 1) * factor;
        }
        return res;
    }
};
