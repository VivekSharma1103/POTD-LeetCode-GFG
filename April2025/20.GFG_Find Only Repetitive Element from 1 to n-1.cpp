class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        long long n = arr.size();
        
        long long sum = accumulate(arr.begin(),arr.end(),0);
        
        int num = sum - ((n-1)*n /2 );
        return num;
    }
};
