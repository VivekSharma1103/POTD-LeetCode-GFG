class Solution {
public:
    bool check(int i, int currsum, string& s, int num) {
        if (i == s.length()) {
            return currsum == num;
        }
        if (currsum > num) {
            return false;
        }
        
        
        for (int j = i; j < s.length(); j++) {
            string sub = s.substr(i, j - i + 1);
            int val = stoi(sub);
            
            if (val > num) break; 
            
            if (check(j + 1, currsum + val, s, num)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int num = 1; num <= n; num++) {
            int sq = num * num;
            string s = to_string(sq);

            if (check(0, 0, s, num)) {
                sum += sq;
            }
        }
        return sum;
    }
};
