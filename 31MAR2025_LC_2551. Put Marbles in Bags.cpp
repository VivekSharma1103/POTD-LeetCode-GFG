class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0;  // No partition needed

        vector<int> pairSums;
        for (int i = 0; i < n - 1; i++) {
            pairSums.push_back(weights[i] + weights[i + 1]);  // Compute pairwise sums
        }

        sort(pairSums.begin(), pairSums.end());  // Sort pair sums

        long long min_cost = 0, max_cost = 0;
        for (int i = 0; i < k - 1; i++) {
            min_cost += pairSums[i];                   // Sum of smallest (k-1) elements
            max_cost += pairSums[n - 2 - i];           // Sum of largest (k-1) elements
        }

        return max_cost - min_cost;
    }};
