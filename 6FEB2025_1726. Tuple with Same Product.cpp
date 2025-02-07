class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,vector<vector<int>>>mp;

        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                mp[nums[i]*nums[j]].push_back({nums[i],nums[j]});
            }
        }

        int c=0;
        for(auto &m:mp)
        {
           
           for(int i=0;i<m.second.size();i++)
           {
               for(int j=i+1;j<m.second.size();j++)
               {
               
                    c+=8;
                
               }
           }

        }
        return c;
    }
};
