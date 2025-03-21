class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
      int n = arr.size();
      if(arr.empty()) return 0;
      if(n<1) return arr[0];
      if(n<2) return max(arr[0],arr[1]);
      int prev1 = 0;
      int prev2 = 0;
      
       for (int num : arr) {
            int newSum = max(prev2, prev1 + num);
            prev1 = prev2;
            prev2 = newSum;
        }

        return prev2;
      
      
    }
};
