class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mp;
        int x = -1;
        int f = 0;
        int n = nums.size();

     
        for(int i : nums) {
            mp[i]++;
        }
        for(auto ele : mp) {
            if(ele.second > n / 2) {
                f = ele.second;
                x = ele.first;
                break;
            }
        }
        if(x == -1) return -1;

        vector<int> freqdom(n, 0);
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == x) {
                count++;
            }
            freqdom[i] = count;
        }

   
        for(int index = 0; index < n - 1; index++) {
            int first = freqdom[index];
            int second = f - first;

            if ((first * 2) > (index + 1) && (second * 2) > (n - (index + 1))) {
                return index;
            }
        }

        return -1;
    }
};
