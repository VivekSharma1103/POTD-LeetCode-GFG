class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char> st;
       for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                // If stack is empty, no opening bracket for this closing bracket
                if (st.empty()) return false;

                char top = st.top();
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    st.pop(); // Valid matching bracket pair
                } 
                else {
                    return false; // Mismatch case
                }
            }
        }
        
        
        if(!st.empty()) return false;
        
        
        return true;
    }
};
