class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        int result = 0;
        
        stack<int> st;
        
        for(int i=0;i<arr.size();i++){
            if (arr[i] != "+" && arr[i] != "-" && arr[i] != "*" && arr[i] != "/") {
           st.push(stoi(arr[i]));
        }

            else{
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                
                if(arr[i] == "+"){
                    st.push(op1+op2);
                }
            else if(arr[i] == "-"){
                    st.push(op1-op2);
                }
               else if(arr[i] == "*"){
                    st.push(op1*op2);
                }
            else if(arr[i] == "/"){
                    st.push(op1/op2);
                }
            }
        }
        
        
        
        
        return result;
    }
};
