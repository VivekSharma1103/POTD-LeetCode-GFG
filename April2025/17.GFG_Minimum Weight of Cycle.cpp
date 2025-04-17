#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        // Adjacency list: each node has a list of (neighbor, weight)
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        int minCycle = INT_MAX;

        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];

            // Dijkstra from u while skipping edge (u,v)
            vector<int> dist(V, INT_MAX);
            dist[u] = 0;

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push(make_pair(0, u));

            while (!pq.empty()) {
                pair<int, int> top = pq.top();
                pq.pop();
                int node = top.second;
                int d = top.first;

                for (int j = 0; j < adj[node].size(); ++j) {
                    int neighbor = adj[node][j].first;
                    int weight = adj[node][j].second;

                    // Skip the edge (u, v)
                    if ((node == u && neighbor == v) || (node == v && neighbor == u)) {
                        continue;
                    }

                    if (dist[neighbor] > dist[node] + weight) {
                        dist[neighbor] = dist[node] + weight;
                        pq.push(make_pair(dist[neighbor], neighbor));
                    }
                }
            }

            if (dist[v] != INT_MAX) {
                minCycle = min(minCycle, dist[v] + w);
            }
        }

        return (minCycle == INT_MAX) ? -1 : minCycle;
    }
};
