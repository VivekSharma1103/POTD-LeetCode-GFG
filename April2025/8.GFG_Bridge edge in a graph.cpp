class Solution {
  public:
    void dfs(int node,vector<vector<int>> &adj,vector<bool> &visited){
        visited[node] = true;
        for(auto &ne:adj[node]){
            if(!visited[ne]){
                dfs(ne,adj,visited);
            }
        }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &e:edges){
        int u = e[0], v = e[1];
        if ((u == c && v == d) || (u == d && v == c)) continue; 
        adj[u].push_back(v);
        adj[v].push_back(u);
        }
        
        vector<bool> visited(V,false);
        
        dfs(c, adj, visited);
        
        return !visited[d];
    }
};
