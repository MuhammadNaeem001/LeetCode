class Solution {
public:
    string countAndSay(int n) {
        // Base case
        if (n == 1) return "1";

        // Get the previous term in the sequence
        string prev = countAndSay(n - 1);
        string result = "";

        // Run-length encode the previous term
        for (int i = 0; i < prev.size(); i++) {
            int count = 1;  // count occurrences of the same digit
            while (i + 1 < prev.size() && prev[i] == prev[i + 1]) {
                count++;
                i++;
            }
            result += to_string(count) + prev[i];
        }

        return result;
    }
};
