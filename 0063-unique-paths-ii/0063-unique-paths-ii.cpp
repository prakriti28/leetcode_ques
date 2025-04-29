class Solution {

private:
    int helper(int i, int j,vector<vector<int>>& grid,vector<vector<int>>&dp) {
        if(i>=0 and j>=0 and grid[i][j]==1) return 0;
        if (i == 0 and j == 0) {
            return 1;
        }
        
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = helper(i-1,j,grid,dp);
        int left= helper(i,j-1,grid,dp);
        return dp[i][j]=up+left;
    }


public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
         return helper(m-1,n-1,obstacleGrid,dp);
    }
};