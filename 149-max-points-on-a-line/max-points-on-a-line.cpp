class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int result = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopeCount;
            int same = 0;   // points overlapping with points[i]
            int localMax = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    same++; // same point
                    continue;
                }

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Normalize slope direction
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = 1; // vertical line
                } else if (dy == 0) {
                    dx = 1; // horizontal line
                }

                string slope = to_string(dy) + "/" + to_string(dx);
                slopeCount[slope]++;
                localMax = max(localMax, slopeCount[slope]);
            }

            result = max(result, localMax + same + 1);
        }

        return result;
    }

private:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
};
