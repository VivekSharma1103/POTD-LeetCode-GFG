
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
      int xor1 = derived[0];
      for(int i=1;i<derived.size();i++){
        xor1^=derived[i];
      }  
      if(xor1==0) return true;
      else return false;
    }
};
