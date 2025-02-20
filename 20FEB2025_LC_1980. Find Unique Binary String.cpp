class Solution {
public:
    // string result = ""; 

    // bool check(string output, vector<string>& nums) {
    //     for (string num : nums) {
    //         if (output == num) return true;
    //     }
    //     return false;
    // }

    // void solve(int n, vector<string>& nums, string output) {
    //     if (output.size() == n) { 
    //         if (!check(output, nums)) { 
    //             result = output;
    //         }
    //         return; 
    //     }

      
    //     if (!result.empty()) return;

     
    //     solve(n, nums, output + "0");
    //     if (!result.empty()) return; 
    //     solve(n, nums, output + "1");
    // }

    string findDifferentBinaryString(vector<string>& nums) {
        // int n = nums.size();
        // string output = "";
        // solve(n, nums, output);
        // return result;
         int n = nums.size();
        string result = "";
        
        // Create a binary string different from each in nums using diagonal method
        for (int i = 0; i < n; i++) {
            result += (nums[i][i] == '0') ? '1' : '0';
        }

        return result;
    }
};
