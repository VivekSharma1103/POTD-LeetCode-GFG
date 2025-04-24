class Solution {
  public:
    int getSingle(vector<int> &nums) {
        // code here
        int result = 0;

    // Go through each bit position (assuming 32-bit integers)
    for (int i = 0; i < 32; ++i) {
        int sum = 0;
        int mask = (1 << i);
        
        for (int num : nums) {
            if (num & mask) {
                sum++;
            }
        }

        if (sum % 3 != 0) {
            result |= mask;
        }
    }

    return result;
    }
};
