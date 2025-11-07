class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        int min_val = nums[0], max_val = nums[0];
        for (int v : nums) {
            min_val = min(min_val, v);
            max_val = max(max_val, v);
        }
        if (min_val == max_val) return 0;  // all same values
        
        int bucketSize = max(1, (max_val - min_val) / (n - 1));
        int bucketCount = (max_val - min_val) / bucketSize + 1;
        
        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        
        // fill buckets
        for (int v : nums) {
            int idx = (v - min_val) / bucketSize;
            bucketMin[idx] = min(bucketMin[idx], v);
            bucketMax[idx] = max(bucketMax[idx], v);
        }
        
        int maxGap = 0;
        int prevMax = bucketMax[0];  // initialize with first bucket’s max
        for (int i = 1; i < bucketCount; i++) {
            if (bucketMin[i] == INT_MAX) {
                // empty bucket, skip
                continue;
            }
            // gap between current bucket’s min and previous non-empty bucket’s max
            maxGap = max(maxGap, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }
        
        return maxGap;
    }
};
