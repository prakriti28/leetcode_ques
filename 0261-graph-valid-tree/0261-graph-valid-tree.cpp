class Solution {

public:
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<int> adj[2001];

        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // queue<int>q;
        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                cnt++;
                queue<pair<int, int>> q;
                q.push({i, -1});

                vis[i] = 1;
                while (!q.empty()) {

                    int node = q.front().first;
                    int par = q.front().second;
                    q.pop();

                    for (auto it : adj[node]) {
                        if (!vis[it]) {
                            q.push({it, node});
                            vis[it] = 1;
                        } else if (par != it) {
                            return false;
                        }
                    }
                }
            }
        }
        return cnt == 1;
    }
};