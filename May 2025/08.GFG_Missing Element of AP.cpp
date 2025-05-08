class Solution {
public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        int d = getCommonDifference(arr);
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int expected = arr[0] + mid * d;
            if (arr[mid] == expected) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return arr[0] + low * d;
    }

private:
    int getCommonDifference(const vector<int> &arr) {
        int d1 = arr[1] - arr[0];
        int d2 = arr[2] - arr[1];
        int d3 = arr[3] - arr[2];
        if (d1 == d2 || d1 == d3) return d1;
        return d2;
    }
};
