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
        int mini = INT_MAX;
        for (int k = 0; k < n; k++) {
            if (k == j)
                continue;
            mini = min(mini, matrix[i][j] + helper(i + 1, k, n, matrix, dp));
        }

        return dp[i][j] = mini;
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = matrix[n - 1][i];
        }
        int mini = INT_MAX;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int ans = INT_MAX;
                for (int k = n - 1; k >= 0; k--) {
                    if (j == k)
                        continue;
                    ans = min(ans, matrix[i][j] + dp[i + 1][k]);
                }
                dp[i][j] = ans;
            }
        }

        // int mini = dp[0][0];
        for (int j = 0; j < n; j++) {
            mini = min(mini, dp[0][j]);
        }
        return mini;
    }
};