class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

        // Loop through every character
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];

            // If operator found
            if (c == '+' || c == '-' || c == '*') {

                // Split into left and right
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Combine all results
                for (int a : left) {
                    for (int b : right) {
                        if (c == '+') result.push_back(a + b);
                        else if (c == '-') result.push_back(a - b);
                        else result.push_back(a * b);
                    }
                }
            }
        }

        // If result is empty → expression is a number
        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        return result;
    }
};
