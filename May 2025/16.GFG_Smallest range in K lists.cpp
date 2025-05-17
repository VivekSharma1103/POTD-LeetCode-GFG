class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int k = arr.size(); // number of lists

        // Min-heap: stores tuples of (value, row index, column index)
        typedef tuple<int, int, int> Element; // (value, row, col)

        priority_queue<Element, vector<Element>, greater<Element>> minHeap;

        int maxi = INT_MIN;
        int start = 0, end = INT_MAX;

        // Push the first element of each list into the heap
        for (int i = 0; i < k; ++i) {
            int value = arr[i][0];
            minHeap.push(make_tuple(value, i, 0));
            maxi = max(maxi, value);
        }

        // Now process the heap
        while (!minHeap.empty()) {
            Element current = minHeap.top();
            minHeap.pop();

            int mini = get<0>(current);
            int row = get<1>(current);
            int col = get<2>(current);

            // Update range if current is smaller
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            // If we've reached the end of a list, stop
            if (col + 1 >= arr[row].size())
                break;

            // Push next element from the same list
            int nextVal = arr[row][col + 1];
            minHeap.push(make_tuple(nextVal, row, col + 1));
            maxi = max(maxi, nextVal);
        }

        return {start, end};
    }
};
