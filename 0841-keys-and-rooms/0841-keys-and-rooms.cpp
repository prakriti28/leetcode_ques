class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < rooms.size(); i++) {
            adj[i] = rooms[i];
        }

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }

        for (int i = 0; i < vis.size(); i++) {
            if (!vis[i]) {
                return false;
            }
        }
        return true;
    }
};