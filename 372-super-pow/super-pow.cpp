class Solution {
public:
    static const int MOD = 1337;

    // fast power with mod
    int powMod(int a, int k) {
        int result = 1;
        a %= MOD;
        while (k > 0) {
            if (k & 1)
                result = (result * a) % MOD;
            a = (a * a) % MOD;
            k >>= 1;
        }
        return result;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty())
            return 1;

        int lastDigit = b.back();
        b.pop_back();

        int part1 = powMod(a, lastDigit);
        int part2 = powMod(superPow(a, b), 10);

        return (part1 * part2) % MOD;
    }
};
