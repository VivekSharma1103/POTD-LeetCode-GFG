class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int n = arr.size() + 1;
        int xor1 = 0, xor2 = 0;

        // XOR all numbers from 1 to n
        for (int i = 1; i <= n; ++i)
            xor1 ^= i;

        // XOR all elements in the array
        for (int num : arr)
            xor2 ^= num;

        return xor1 ^ xor2;
    }
};
