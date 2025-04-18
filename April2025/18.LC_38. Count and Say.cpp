class Solution {
public:
    string count(string &result) {
        if (result.empty()) return "1"; 
        string newResult = "";
        int count = 1;

       
        for (int i = 1; i < result.size(); i++) {
            if (result[i] == result[i - 1]) {
                count++;
            } else {
                newResult += to_string(count) + result[i - 1];  
                count = 1;
            }
        }
        newResult += to_string(count) + result.back();  
        
        return newResult;
    }

    string countAndSay(int n) {
        string result = "1";  

        for (int i = 1; i < n; i++) {
            result = count(result);  
        }

        return result;
    }
};
