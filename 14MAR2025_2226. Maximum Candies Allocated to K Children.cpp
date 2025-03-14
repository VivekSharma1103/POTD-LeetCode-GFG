class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);
        if (sum < k) return 0; 
        
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canDistribute(candies, k, mid)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }

private:
    bool canDistribute(vector<int>& candies, long long k, int size) {
        long long count = 0;
        for (int candy : candies) {
            count += candy / size;
            if (count >= k) return true;
        }
        return count >= k;
    }
};
