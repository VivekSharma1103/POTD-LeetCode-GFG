class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]) return arr[i];
        }
        return arr[n-1];
    }
};
