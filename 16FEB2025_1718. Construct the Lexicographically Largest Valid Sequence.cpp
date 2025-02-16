class Solution {
public:
   bool check(int i, int n, vector<int>& result, vector<bool>& used) {
       if (i >= result.size()) return true; 
       
       if (result[i] != -1) return check(i + 1, n, result, used);  

       for (int num = n; num >= 1; num--) {  
           if (used[num]) continue; 
           
        
           result[i] = num;
           used[num] = true;

           if (num == 1 || (i + num < result.size() && result[i + num] == -1)) {  
               if (num > 1) result[i + num] = num;

               if (check(i + 1, n, result, used)) return true;  
               if (num > 1) result[i + num] = -1;  
           }

           result[i] = -1;  
           used[num] = false;
       }
       return false;
   }

   vector<int> constructDistancedSequence(int n) {
       vector<int> result(2 * n - 1, -1);
       vector<bool> used(n + 1, false);

       check(0, n, result, used);
       return result;
   }
};
