class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Step 1: Create adjacency list
        vector<vector<int>> adj(V);
        for(auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]); // Directed edge
        }

        // Step 2: Calculate in-degree of each node
        vector<int> inDegree(V, 0);
        for(int u = 0; u < V; ++u) {
            for(int v : adj[u]) {
                inDegree[v]++;
            }
        }

        // Step 3: Push all nodes with in-degree 0 to queue
        queue<int> q;
        for(int i = 0; i < V; ++i) {
            if(inDegree[i] == 0)
                q.push(i);
        }

        // Step 4: Process nodes
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for(int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If count != V, there is a cycle
        return count != V;
    }
};
