class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int xor_all = 0;

        // Step 1: Get XOR of all elements
        for (int num : arr) {
            xor_all ^= num;
        }

        // Step 2: Get rightmost set bit in xor_all
        int set_bit = xor_all & -xor_all;

        int num1 = 0, num2 = 0;

        // Step 3: Divide numbers into two groups and XOR separately
        for (int num : arr) {
            if (num & set_bit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }

        // Step 4: Return result in increasing order
        if (num1 < num2) {
            return {num1, num2};
        } else {
            return {num2, num1};
        }
    }
};
