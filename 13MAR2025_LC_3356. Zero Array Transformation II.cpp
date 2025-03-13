class Solution {
public:
  bool canZeroArray(vector<int> nums, vector<vector<int>>& queries, int k) {
    int n = nums.size();
    vector<int> diff(n + 1, 0);

    // Apply the first k queries using a difference array
    for (int i = 0; i < k; i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        int val = queries[i][2];
        diff[l] -= val;
        diff[r + 1] += val;
    }

    // Apply the difference array to nums
    int current = 0;
    for (int i = 0; i < n; i++) {
        current += diff[i];
        if (nums[i] + current > 0) {
            return false; // If any element remains positive, return false
        }
    }

    return true;
}

int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int left = 0, right = queries.size();
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canZeroArray(nums, queries, mid)) {
            result = mid;
            right = mid - 1; // Try to minimize k
        } else {
            left = mid + 1;
        }
    }

    return result;
}
};
