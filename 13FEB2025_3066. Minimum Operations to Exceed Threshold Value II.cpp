class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
      priority_queue<long long, vector<long long>, greater<long long>> minHeap;      
    int ans = 0;
    
      for(int &num : nums){
        minHeap.push(num);
      }

      while(minHeap.top() < k){
        long long x = minHeap.top();
        minHeap.pop();
        long long y = minHeap.top();
        minHeap.pop();
        long long val = min(x,y) * 2 + max(x,y);
        ans++;
        minHeap.push(val);
      }
    return ans;
    }
};
