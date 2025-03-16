class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        if (arr[0] == 0) return -1;

        int maxReach = arr[0];
        int steps = arr[0];
        int jumps = 1;

        for (int i = 1; i < n; i++) {
            // If we reached the last index
            if (i == n - 1) return jumps;

            // Update the farthest we can reach
            maxReach = max(maxReach, i + arr[i]);
            steps--;

            // If steps become zero, we need to jump
            if (steps == 0) {
                jumps++;
                if (i >= maxReach) return -1; // If we can't go further, return -1
                steps = maxReach - i;
            }
        }
        return -1;
    }
};
