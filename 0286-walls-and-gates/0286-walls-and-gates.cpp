class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            rooms[row][col] = dis;
            q.pop();

            for (auto dir : directions) {
                int nrow = row + dir.first;
                int ncol = col + dir.second;

                if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and
                    !vis[nrow][ncol] and rooms[nrow][ncol] != -1) {
                    q.push({{nrow, ncol}, dis + 1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
};