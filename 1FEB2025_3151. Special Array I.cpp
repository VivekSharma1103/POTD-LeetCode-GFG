class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
       int n = nums.size();
        if(n==1) return true;
        
       else {
          for(int i=1;i<n;i++){
                if(nums[i]%2==0) {
                    if(nums[i-1]%2==0){
                        return false;
                    }
                }
                else{
                    if(nums[i-1]%2!=0)
                    return false;
                }
          }
       }
        return true;
    }
};
