class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int count = 0, candidate = -1;
        
        // Step 1: Find a potential candidate
        for (int num : arr) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        // Step 2: Verify if the candidate is actually the majority
        count = 0;
        for (int num : arr) {
            if (num == candidate) {
                count++;
            }
        }

        if (count > arr.size() / 2) {
            return candidate;
        } else {
            return -1;
        }
    }
};
