class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;
        int visited = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : rooms[node]) {
                if (!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                    visited++;
                }
            }
        }


        return visited==n;
    }
};