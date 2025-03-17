class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int, int> mp;
        
        // Count frequency of each element
        for (int num : nums) {
            mp[num]++;
        }
        
        // Check if pairs can be formed
        for (auto &i : mp) {
            if (i.second % 2 != 0) {
                return false;
            }
        }
        
        return true;
    }
};
