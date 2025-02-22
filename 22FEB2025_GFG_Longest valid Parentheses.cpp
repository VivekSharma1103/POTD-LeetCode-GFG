class Solution {
  public:
    int maxLength(string& A) {
        // code here
        int sol = 0, curr = 0, start = -1;
    int i = 0;
    stack<int> st;
    st.push(-1);
    while (i < A.size()) {
        if (A[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (!st.empty()) {
                sol = max(i - st.top(), sol);
            } else {
                st.push(i);
            }
        }
        i++;
    }
    return sol;
    }
};
