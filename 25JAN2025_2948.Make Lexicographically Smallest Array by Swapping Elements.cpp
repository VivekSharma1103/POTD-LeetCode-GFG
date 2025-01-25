class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
       // sort the array to make groups;
       int n=nums.size();
        vector<int> vec = nums;
        sort(begin(vec),end(vec));
       
       // make groups based on the limit in map and store the group no of each element in a map

        int groupNo = 0;
        unordered_map<int,int> numGroup;

        numGroup[vec[0]] = groupNo;


         unordered_map<int,list<int>> grouptolist;
         grouptolist[groupNo].push_back(vec[0]); 

        for(int i=1;i<n;i++){
            if(abs(vec[i]-vec[i-1]) > limit){
                groupNo += 1;
            }
            numGroup[vec[i]] = groupNo;
            grouptolist[groupNo].push_back(vec[i]);
        }

        // now merge the answers of different group
        vector<int> result(n);
        for(int i=0;i<n;i++){
            int num = nums[i];
            int group = numGroup[num];

            // smallest available number in this group
            result[i] = *(grouptolist[group].begin());
            grouptolist[group].pop_front();
        }

        return result;
    }
};
