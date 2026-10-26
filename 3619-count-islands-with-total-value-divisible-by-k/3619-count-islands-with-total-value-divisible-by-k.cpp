class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] != 0 && !visited[i][j]) {

                    queue<pair<int, int>> q;

                    q.push({i, j});
                    visited[i][j] = true;

                    long long sum = 0;

                    while (!q.empty()) {

                        auto it = q.front();
                        int r = it.first;
                        int c = it.second;

                        sum += grid[r][c];
                        q.pop();

                        for (int d = 0; d < 4; d++) {

                            int nr = r + dr[d];
                            int nc = c + dc[d];

                            if (nr >= 0 && nc >= 0 &&
                                nr < n && nc < m &&
                                !visited[nr][nc] &&
                                grid[nr][nc] != 0) {

                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }

                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};