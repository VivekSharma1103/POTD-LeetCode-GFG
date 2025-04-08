class Solution {
public:
    unordered_map<int,int>mp;
    bool checkdup(vector<int> &nums){
        mp.clear();
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>1){
                return false;
            }
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        
        if(checkdup(nums)){
            return 0;
        }
        
        int count = 0;
        while( !checkdup(nums)){
            int rem = min(3,(int)nums.size());
           nums.erase(nums.begin(), nums.begin() + rem);
            count++;
        }
        return count;
    }
};
