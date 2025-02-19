class Solution {
public:
    int count = 0;
    string result = "";

    void generateHappyString(int n, string output, vector<char> &option, int k) {
        if (output.size() == n) {
            count++;
            if (count == k) {
                result = output;
            }
            return;
        }

        for (char ch : option) {
            if (output.empty() || output.back() != ch) {  
                generateHappyString(n, output + ch, option, k);
                if (!result.empty()) return; 
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<char> option = {'a', 'b', 'c'};
        generateHappyString(n, "", option, k);
        return result;
    }
};
