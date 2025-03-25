class Solution {
public:
    // Type alias for pair to make code more readable
    using P = pair<int, int>;

    // Custom comparator for sorting intervals
    bool static customComparator(const P& a, const P& b) {
        // If start points are same, sort by end point in descending order
        if (a.first == b.first) {
            return a.second > b.second;
        }
        // Otherwise, sort by start point in ascending order
        return a.first < b.first;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // Separate x and y axis intervals
        vector<P> x_axis;
        vector<P> y_axis;

        // Populate x and y axis intervals
        for (auto& rect : rectangles) {
            x_axis.push_back({rect[0], rect[2]});
            y_axis.push_back({rect[1], rect[3]});
        }

        // Sort x and y axis intervals using custom comparator
        sort(begin(x_axis), end(x_axis), customComparator);
        sort(begin(y_axis), end(y_axis), customComparator);

        // Check x-axis intervals
        int count = 0;
        int start = 0, end = 0;
        for (auto& x : x_axis) {
            // If current interval starts after previous interval ends
            if (x.first >= end) {
                // Start a new non-overlapping interval
                count++;
                start = x.first;
                end = x.second;
            } else {
                // Merge overlapping intervals
                start = min(start, x.first);
                end = max(end, x.second);
            }

            // If we have 3 non-overlapping intervals, return true
            if (count == 3) {
                return true;
            }
        }

        // Reset for y-axis check
        count = 0;
        start = 0, end = 0;
        for (auto& y : y_axis) {
            // Same logic as x-axis check
            if (y.first >= end) {
                count++;
                start = y.first;
                end = y.second;
            } else {
                start = min(start, y.first);
                end = max(end, y.second);
            }

            // If we have 3 non-overlapping intervals, return true
            if (count == 3) {
                return true;
            }
        }

        // If no valid cuts found
        return false;
    }
};
