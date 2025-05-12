class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        vector<int> freq(10, 0);

        // Step 1: Count frequency of digits
        for (int digit : digits) {
            freq[digit]++;
        }

        // Step 2: Check all valid 3-digit even numbers
        for (int num = 100; num <= 999; ++num) {
            if (num % 2 != 0) continue;  // must be even

            int a = num / 100;           // hundreds
            int b = (num / 10) % 10;     // tens
            int c = num % 10;            // units

            // Create a temp frequency array to track usage
            vector<int> tempFreq(10, 0);
            tempFreq[a]++;
            tempFreq[b]++;
            tempFreq[c]++;

            // Check if all digits exist in sufficient quantity
            bool valid = true;
            for (int d = 0; d < 10; ++d) {
                if (tempFreq[d] > freq[d]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                result.push_back(num);
            }
        }

        return result;
    }
};
