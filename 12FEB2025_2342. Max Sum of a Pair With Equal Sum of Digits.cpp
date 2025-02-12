class Solution {
public:
    int maximumSum(vector<int>& nums) {
        if (nums.size() < 2) return -1;

        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        int maxSum = -1;

        for (int num : nums) {
            int sum = 0, x = num;
            
            // Calculate digit sum
            while (x) {
                sum += (x % 10);
                x /= 10;
            }

            auto &minHeap = mp[sum];

            // Maintain only the top 2 largest numbers in the heap
            minHeap.push(num);
            if (minHeap.size() > 2) {
                minHeap.pop(); // Remove smallest to keep only 2 largest
            }
        }

        // Find max sum of two largest numbers in each digit sum group
        for (auto &it : mp) {
            auto &minHeap = it.second;
            if (minHeap.size() == 2) {
                int num1 = minHeap.top(); minHeap.pop();
                int num2 = minHeap.top();
                maxSum = max(maxSum, num1 + num2);
            }
        }

        return maxSum;
    }
};
