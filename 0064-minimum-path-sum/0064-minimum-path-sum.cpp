class Solution {

private:

    int helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==0 and j==0 )return grid[i][j];
        if(i<0 or j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=grid[i][j]+helper(i-1,j,grid,dp);
        int left=grid[i][j]+helper(i,j-1,grid,dp);
        return dp[i][j]=min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return helper(n-1,m-1,grid,dp);
        
    }
};