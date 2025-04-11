class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it,adj,vis);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;

        vector<vector<int>> adj(n);

        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        int connection = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                connection++;
                dfs(i, adj, vis);
            }
        }
        return connection - 1;
    }
};