class Solution {
public:
int count;
    void solve(vector<int>&vec){
        count++;
        for(int i=0;i<26;i++){
            if(vec[i]==0) continue;
            vec[i]--;
            solve(vec);
            vec[i]++;
        }
    }
    int numTilePossibilities(string tiles) {
        count = 0;
        vector<int> vec(26,0);
        for(auto &s : tiles){
           vec[s-'A']++;
        }
        solve(vec);
        return count - 1;
    }
};
