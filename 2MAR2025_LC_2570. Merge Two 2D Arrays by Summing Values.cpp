class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mp;  

        for (auto &n : nums1) {
            mp[n[0]] += n[1];  
        }

        for (auto &n : nums2) {
            mp[n[0]] += n[1];  
        }

        vector<vector<int>> ans;
        for (auto &entry : mp) {
            ans.push_back({entry.first, entry.second});  
        }

        return ans;
    }
};
