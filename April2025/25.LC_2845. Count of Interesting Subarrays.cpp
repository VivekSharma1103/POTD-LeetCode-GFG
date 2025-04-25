class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> countMap;
        countMap[0] = 1;  // base case: prefix sum is 0
        long long result = 0;
        int prefixCount = 0;

        for (int num : nums) {
            // increment prefixCount if current num satisfies condition
            if (num % modulo == k) {
                prefixCount++;
            }

            int modVal = prefixCount % modulo;
            // we want to find countMap[(modVal - k + modulo) % modulo]
            // because (modVal - prevVal) % modulo == k
            int target = (modVal - k + modulo) % modulo;

            if (countMap.find(target) != countMap.end()) {
                result += countMap[target];
            }

            countMap[modVal]++;
        }

        return result;
    }
};
