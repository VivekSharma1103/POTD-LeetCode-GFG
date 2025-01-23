class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
       int rows = grid.size();
       int cols = grid[0].size();

       vector<int> rcount(rows,0);
       vector<int> ccount(cols,0);

       for(int i=0;i<rows;i++)
       {
        for(int j=0;j<cols;j++){
            if(grid[i][j]==1){
                rcount[i]++;
                ccount[j]++;
            }
        }
       }
       int count = 0;

         for(int i=0;i<rows;i++)
       {
        for(int j=0;j<cols;j++){
            if(grid[i][j]==1 && (rcount[i]>1 || ccount[j]>1)){
                count+=1;
            }
        }
       }


     
       return count;
    }
};
