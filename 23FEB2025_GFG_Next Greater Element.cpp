class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1); // Initialize result array with -1
        stack<int> s; // Stack to store elements

        for (int i = n - 1; i >= 0; i--) { // Traverse from right to left
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop(); // Remove smaller elements
            }

            if (!s.empty()) {
                result[i] = s.top(); // Top of the stack is the next greater element
            }

            s.push(arr[i]); // Push current element onto stack
        }

        return result;
    }
};
