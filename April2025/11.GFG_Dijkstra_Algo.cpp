class Solution {
  public:
    int selectMinVertex(vector<int>& value, vector<bool>& processed) {
        int minimum = INT_MAX;
        int vertex = -1;
        for (int i = 0; i < value.size(); i++) {
            if (!processed[i] && value[i] < minimum) {
                minimum = value[i];
                vertex = i;
            }
        }
        return vertex;
    }

   vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
    vector<vector<pair<int, int>>> adj(V);
    
    // Convert edge list to adjacency list
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});  // remove this if the graph is directed
    }

    vector<int> value(V, INT_MAX);
    vector<bool> processed(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    value[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (processed[u]) continue;
        processed[u] = true;

        for (auto& it : adj[u]) {
            int v = it.first;
            int wt = it.second;

            if (!processed[v] && value[u] + wt < value[v]) {
                value[v] = value[u] + wt;
                pq.push({value[v], v});
            }
        }
    }

    return value;
}

};
