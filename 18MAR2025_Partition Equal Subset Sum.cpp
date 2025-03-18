class Solution {
public:
    bool check(vector<int>& arr, int index, int sum) {
        if (sum == 0) {
            return true;
        }
        if (index >= arr.size() || sum < 0) {
            return false;
        }
        
        // Either include the current element or exclude it
        return check(arr, index + 1, sum - arr[index]) || check(arr, index + 1, sum);
    }

    bool equalPartition(vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        
        
        if (total % 2 != 0) {
            return false;
        }
        
        int target = total / 2;
        return check(arr, 0, target);
    }
};
