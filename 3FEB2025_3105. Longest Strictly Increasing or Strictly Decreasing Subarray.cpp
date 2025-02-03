class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1;
        int mx = 1;  

        int n = nums.size();

        for (int i = 1; i < n; i++) {
           
            if (nums[i] > nums[i - 1]) {
                inc++;
            } else {
                inc = 1; 
            }

        
            if (nums[i] < nums[i - 1]) {
                dec++;
            } else {
                dec = 1; 
            }

            mx = max(mx, max(inc, dec)); 
        }

        return mx;
    }
};
