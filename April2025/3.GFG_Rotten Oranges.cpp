class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        int count1 = 0;
        queue<tuple<int, int, int>> q;
        vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] == 1) count1++;
                if(mat[i][j] == 2) q.push(make_tuple(i, j, 0));
            }
        }
        if(count1 == 0) return 0;
        
        int tme = 0, convert_count = 0;

        while(!q.empty() && count1 - convert_count != 0) {
            auto p = q.front();
            q.pop();
            int i = get<0>(p);
            int j = get<1>(p);
            int t = get<2>(p);
            
            for(auto &dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ < 0 || j_ < 0 || i_ >= mat.size() || j_ >= mat[0].size()) continue;
                if(mat[i_][j_] == 1) {
                    convert_count++;
                    mat[i_][j_] = 2;  
                    q.push(make_tuple(i_, j_, t+1));
                    tme = t + 1;  
                }
            }
        }

        return (convert_count == count1) ? tme : -1;
    }
};
