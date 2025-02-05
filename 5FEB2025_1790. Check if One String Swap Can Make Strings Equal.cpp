class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
       vector<int> diff;
       if (s1 == s2) return true;
       for(int i=0;i<s1.length();i++)
        if(s1[i]!=s2[i]) diff.push_back(i);
       
       if(diff.size()!=2) return false;
       int i1 = diff[0],i2=diff[1];
       return s1[i1] == s2[i2] && s1[i2] == s2[i1];
    }
};
