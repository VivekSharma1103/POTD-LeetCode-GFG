class Solution {
  public:
    
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> ans;
        int n = adj.size();
        vector<bool> visited(n, false);
        queue<int> q;

        // Start BFS from node 0
        int u = 0;
        q.push(u);
        visited[u] = true;
    
        while (!q.empty()) {
            int node = q.front(); // Get the front element
            q.pop();
            ans.push_back(node);

            // Traverse neighbors
            for (int &v : adj[node]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
          
        return ans;
    }
};
