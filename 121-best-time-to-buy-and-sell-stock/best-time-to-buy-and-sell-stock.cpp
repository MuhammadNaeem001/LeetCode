class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;   // store the lowest price seen so far
        int maxProfit = 0;        // store the maximum profit

        for (int price : prices) {
            // check if selling today gives a better profit
            maxProfit = max(maxProfit, price - minPrice);

            // update minimum price if today's price is lower
            minPrice = min(minPrice, price);
        }

        return maxProfit;
    }
};
