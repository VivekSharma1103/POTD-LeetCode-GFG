class Solution {
  public:
    string findOrder(vector<string> &words) {
        vector<vector<int>> g(26);
        vector<int> in(26), seen(26);

        // Mark seen characters
        for (auto &s : words)
            for (char c : s)
                seen[c - 'a'] = 1;

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string &a = words[i], &b = words[i + 1];
            int j = 0, n = min(a.size(), b.size());
            while (j < n && a[j] == b[j]) j++;
            if (j == n && a.size() > b.size()) return ""; // Invalid case
            if (j < n) {
                g[a[j] - 'a'].push_back(b[j] - 'a');
                in[b[j] - 'a']++;
            }
        }

        // Topological Sort (Kahn's Algorithm)
        queue<int> q;
        for (int i = 0; i < 26; i++)
            if (seen[i] && in[i] == 0)
                q.push(i);

        string res;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            res += u + 'a';
            for (int v : g[u]) {
                if (--in[v] == 0)
                    q.push(v);
            }
        }

        // Check if all seen nodes are processed (i.e., no cycle)
        for (int i = 0; i < 26; i++)
            if (seen[i] && in[i])
                return "";

        return res;
    }
};
