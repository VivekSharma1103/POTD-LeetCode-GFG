class Solution {
public:
    int kadane(vector<int>&nums){
           int sum = 0;
           int curr_sum = 0;

          for(int i=0;i<nums.size();i++)
          {
              curr_sum += nums[i];
              if(curr_sum < 0){
                curr_sum = 0;
              }
              sum = max(curr_sum,sum);
          }


           return sum;
    }
    int reversekadane(vector<int>&nums){
         int sum = 0;
           int curr_sum = 0;

          for(int i=0;i<nums.size();i++)
          {
              curr_sum += nums[i];
              if(curr_sum > 0){
                curr_sum = 0;
              }
              sum = min(curr_sum,sum);
          }


           return sum;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int val1 = abs(kadane(nums));
        int val2 = abs(reversekadane(nums));
        return val1 > val2 ? val1:val2;
    }
};
