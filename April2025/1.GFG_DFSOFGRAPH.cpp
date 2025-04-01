class Solution {
  public:
    vector<int> ans;
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<vector<int>>& adj,int u,vector<bool>&visited){
        if(visited[u]==true){
            return;
        }
         
         visited[u] = true;
         ans.push_back(u);
        for(int &v : adj[u]){
            if(!visited[v]){
               
                dfs(adj,v,visited);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
     
        int n = adj.size();
        vector<bool> visited(n,false);
        
        dfs(adj,0,visited);
        return ans;
        
    }
};
