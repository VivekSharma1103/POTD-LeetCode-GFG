class Solution {
  public:
    bool isCycleDFS(vector<vector<int>>& adj,int u,vector<bool>& visited,int parent){
        visited[u] = true;
        for(int &v:adj[u]){
            if(v==parent) continue;
            if(visited[v]) return true;
            if(isCycleDFS(adj,v,visited,u)){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& adj) {
        // Code here
       vector<bool> visited(V,false);
       for(int i=0;i<V;i++){
           if(!visited[i] && isCycleDFS(adj,i,visited,-1)){
               return true;
           }
       }
       return false;
    }
};
