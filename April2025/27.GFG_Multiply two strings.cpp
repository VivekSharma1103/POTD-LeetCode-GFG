class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Helper lambda to remove leading zeros
        auto strip_leading_zeros = [](const string& s) {
            int i = 0;
            while (i < s.size() && s[i] == '0') i++;
            return (i == s.size()) ? "0" : s.substr(i);
        };
        
        // Handle sign
        bool neg = false;
        if (!s1.empty() && s1[0] == '-') {
            neg = !neg;
            s1 = s1.substr(1);
        }
        if (!s2.empty() && s2[0] == '-') {
            neg = !neg;
            s2 = s2.substr(1);
        }
        
        // Remove leading zeros
        s1 = strip_leading_zeros(s1);
        s2 = strip_leading_zeros(s2);
        
        // If either is "0", result is "0"
        if (s1 == "0" || s2 == "0") return "0";
        
        // Result array to store the product digits
        vector<int> res(s1.size() + s2.size(), 0);
        
        // Multiply each digit
        for (int i = s1.size() - 1; i >= 0; i--) {
            for (int j = s2.size() - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + res[i + j + 1];
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        
        // Convert result array to string
        string result = "";
        bool leading_zero = true;
        for (int num : res) {
            if (leading_zero && num == 0) continue;
            leading_zero = false;
            result += (num + '0');
        }
        
        // Add negative sign if needed
        if (neg) result = '-' + result;
        
        return result;
    }
};
