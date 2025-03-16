class Solution {
public:
    bool isPossible(vector<int>& ranks, long long mid, int cars) {
        long long carFixed = 0;
        for (int r : ranks) {
            carFixed += sqrt(mid / r);
            if (carFixed >= cars) return true; 
        }
        return carFixed >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();

       
        int maxRank = *max_element(begin(ranks), end(ranks));
        long long l = 1;
        long long r = 1LL * maxRank * cars * cars;

        long long result = -1;
        while (l <= r) {
            long long mid = l + (r - l) / 2;

            if (isPossible(ranks, mid, cars)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1; 
            }
        }
        return result;
    }
};
