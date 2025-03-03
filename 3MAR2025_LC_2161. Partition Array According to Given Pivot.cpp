class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1;
        
        // First pass: Place elements smaller than pivot
        for (int num : nums) {
            if (num < pivot) result[left++] = num;
        }
        
        // Second pass: Place elements equal to pivot
        for (int num : nums) {
            if (num == pivot) result[left++] = num;
        }

        // Third pass: Place elements greater than pivot
        for (int num : nums) {
            if (num > pivot) result[left++] = num;
        }

        return result;
    }
};
