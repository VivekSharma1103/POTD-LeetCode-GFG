class Solution {
public:
    long long maximumTripletValue(vector<int>& v) {
        int n = v.size();
        if (n < 3) return 0; 

        long long maxA = v[0];      
        long long maxA_B = LLONG_MIN;
        long long maxA_B_C = 0;    

        for (int j = 1; j < n - 1; j++) {
            maxA_B = max(maxA_B, maxA - v[j]); 
            maxA = max(maxA, (long long)v[j]); 
            maxA_B_C = max(maxA_B_C, maxA_B * (long long)v[j + 1]); 
        }

        return maxA_B_C;
    }
};
