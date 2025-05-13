class Solution {
private:
    int helper(int i, int j, int n, vector<vector<int>>& matrix,
               vector<vector<int>>& dp) {
        if (j < 0 || j > n - 1)
            return 1e9;
        if (i == n - 1)
            return matrix[n - 1][j];
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int bottom = matrix[i][j] + helper(i + 1, j, n, matrix, dp);
        int br = matrix[i][j] + helper(i + 1, j - 1, n, matrix, dp);
        int bl = matrix[i][j] + helper(i + 1, j + 1, n, matrix, dp);

        return dp[i][j] = min(bottom, min(br, bl));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int bottom = matrix[i][j] + dp[i + 1][j];
                int br = matrix[i][j];
                if (j - 1 >= 0) { br += dp[i + 1][j - 1]; }
                else {
                    br=1e8;
                }

                int bl = matrix[i][j];
                if (j + 1 < n) {
                    bl += dp[i + 1][j + 1];
                } else {
                    bl = 1e8;
                }

                dp[i][j] = min(bottom, min(br, bl));
            }
        }
        int mini = dp[0][0];
        for (int j = 1; j < n; j++) {
            mini = min(mini, dp[0][j]);
        }
        return mini;
    }
};