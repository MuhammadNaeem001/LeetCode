class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;

        // Step 1: initial penalty (shop closed all time)
        for (char c : customers) {
            if (c == 'Y') penalty++;
        }

        int minPenalty = penalty;
        int bestHour = 0;

        // Step 2: move hour by hour
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                penalty--;   // now shop is open
            } else {
                penalty++;   // open but no customer
            }

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }

        return bestHour;
    }
};
