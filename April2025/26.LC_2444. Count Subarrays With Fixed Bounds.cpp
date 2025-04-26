class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long count = 0;
        int last_invalid = -1;
        int last_min = -1, last_max = -1;

        for (int i = 0; i < n; ++i) {
            // If out of bounds
            if (nums[i] < minK || nums[i] > maxK) {
                last_invalid = i;
            }

            if (nums[i] == minK) last_min = i;
            if (nums[i] == maxK) last_max = i;

            // Count valid subarrays ending at i
            count += max(0, min(last_min, last_max) - last_invalid);
        }

        return count;
    }
};
