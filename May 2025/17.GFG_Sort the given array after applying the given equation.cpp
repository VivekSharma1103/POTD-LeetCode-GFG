class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        int n = arr.size();
        vector<int> result(n);
        int i = 0, j = n - 1;
        
        auto f = [&](int x) {
            return A * x * x + B * x + C;
        };
        
        int index = (A >= 0) ? n - 1 : 0;

        while (i <= j) {
            int val_i = f(arr[i]);
            int val_j = f(arr[j]);

            if (A >= 0) {
                // We want to place bigger values at the end
                if (val_i > val_j) {
                    result[index--] = val_i;
                    i++;
                } else {
                    result[index--] = val_j;
                    j--;
                }
            } else {
                // We want to place smaller values at the start
                if (val_i < val_j) {
                    result[index++] = val_i;
                    i++;
                } else {
                    result[index++] = val_j;
                    j--;
                }
            }
        }

        return result;
    }
};
