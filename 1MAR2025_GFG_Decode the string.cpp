
class Solution {
public:
    string decodedString(string &s) {
        stack<string> st;
        stack<int> numStack;
        string currString = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');  // Build the number
            } 
            else if (c == '[') {
                numStack.push(num);  // Store multiplier
                st.push(currString); // Store previous string state
                num = 0;
                currString = "";
            } 
            else if (c == ']') {
                string temp = currString;
                int repeatCount = numStack.top();
                numStack.pop();
                
                currString = st.top();
                st.pop();

                while (repeatCount--) {
                    currString += temp;  // Repeat the pattern
                }
            } 
            else {
                currString += c;  // Append normal characters
            }
        }

        return currString;
    }
};
