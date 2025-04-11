class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {

        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>>directions={{-1,0},{1,0},{0,1},{0,-1}};

        for(auto dir:directions){
            int nrow=dir.first+row;
            int ncol=dir.second+col;
            if(nrow>=0 and ncol>=0 and nrow<n and ncol<m
            and !vis[nrow][ncol] and grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,vis);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (!vis[i][0] and grid[i][0] == 1) {
                dfs(i, 0, grid, vis);
            }
            if (!vis[i][m - 1] and grid[i][m - 1] == 1) {
                dfs(i, m - 1, grid, vis);
            }
        }

        for (int j = 0; j < m; j++) {
            if (!vis[0][j] and grid[0][j]==1) {
                dfs(0, j, grid, vis);
            }
            if (!vis[n - 1][j] and grid[n - 1][j]) {
                dfs(n - 1, j, grid, vis);
            }
        }
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] and grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};