class Solution {
public:
    int minimumRecolors(string blocks, int k) {
    
        int minc = INT_MAX;
        
        for(int i=0;i<blocks.length()-k+1;i++)
        {
           int count = 0;
           for(int j=i;j<i+k;j++){
              if(blocks[j]=='W'){
                   count++;
              }
           }
           minc = min(minc,count);
        }
        return minc;
    }
};
