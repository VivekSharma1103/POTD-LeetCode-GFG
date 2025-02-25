class Solution {
  public:
    int getMaxArea(vector<int> &heights) {
      
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> st;

    // Finding nearest smaller to left
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        left[i] = (st.empty()) ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop(); // Clear stack for right calculations

    // Finding nearest smaller to right
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        right[i] = (st.empty()) ? n : st.top();
        st.push(i);
    }

    // Calculate maximum area
    int max_area = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        max_area = max(max_area, heights[i] * width);
    }

    return max_area;

    }
};
