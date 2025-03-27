class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        map<int, int> mp;
        int n = arr.size();


        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;       
            mp[dep[i] + 1]--;    
        }

        int maxPlatforms = 0;
        int platforms = 0;

       
        for (auto it : mp) {
            platforms += it.second;             
            maxPlatforms = max(maxPlatforms, platforms);
        }

        return maxPlatforms;
    }
};
