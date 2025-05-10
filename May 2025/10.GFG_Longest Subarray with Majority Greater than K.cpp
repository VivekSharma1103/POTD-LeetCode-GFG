class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> temp(n);
        
        // Step 1: Convert the array to +1 and -1
        for(int i = 0; i < n; i++) {
            if(arr[i] > k) temp[i] = 1;
            else temp[i] = -1;
        }

        // Step 2: Prefix sum and map to store first occurrence
        unordered_map<int, int> prefixIndex;
        int maxLen = 0, prefixSum = 0;

        for(int i = 0; i < n; i++) {
            prefixSum += temp[i];
            
            if(prefixSum > 0) {
                maxLen = i + 1;
            } else {
                if(prefixIndex.find(prefixSum - 1) != prefixIndex.end()) {
                    maxLen = max(maxLen, i - prefixIndex[prefixSum - 1]);
                }
            }

            // Store first occurrence of this prefix sum
            if(prefixIndex.find(prefixSum) == prefixIndex.end()) {
                prefixIndex[prefixSum] = i;
            }
        }

        return maxLen;
    }
};
