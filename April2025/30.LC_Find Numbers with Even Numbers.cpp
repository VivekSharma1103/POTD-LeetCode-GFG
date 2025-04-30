class Solution {
public:
int count = 0;
    void check(int n){
        int c = 0;
     while(n>0){
         n=n/10;
         c++;
     }
     if(c%2==0){
        count++;
     }
    }
    int findNumbers(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
          check(nums[i]);
        }
        return count;
    }
};
