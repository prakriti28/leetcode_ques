import sys
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n=len(grid)
        m=len(grid[0])
        dp=[[sys.maxsize for j in range(m+1)]for i in range(n+1)]
        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                if i==n-1 and j==m-1:
                    dp[i][j]=grid[i][j]
                    # print(dp[i][j])
                else:
                   


                        ans1=dp[i+1][j]
                        ans2=dp[i][j+1]
                     
                        dp[i][j]=(grid[i][j]+min(ans1,ans2))
                    # print(dp[i][j])
        return dp[0][0]
