class Solution {
public:
    bool canPick(vector<int>& nums, int maxCap, int k) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= maxCap) {
                count++;
                i++;  
            }
            if (count >= k) return true;
        }
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPick(nums, mid, k)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
