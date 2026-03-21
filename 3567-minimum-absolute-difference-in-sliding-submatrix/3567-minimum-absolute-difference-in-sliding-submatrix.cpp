class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res;

        for (int i = 0; i + k <= n; i++) {
            vector<int> temp;
            for (int j = 0; j + k <= m; j++) {
                vector<int> v;

                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        v.push_back(grid[x][y]);
                    }
                }
                sort(v.begin(), v.end());
                int mn = INT_MAX;
                for (int z = 1; z < v.size(); z++) {
                    if (v[z] != v[z - 1]) {
                        mn = min(abs(v[z] - v[z - 1]), mn);
                    }
                }
                if (mn != INT_MAX)
                    temp.push_back(mn);
                else
                    temp.push_back(0);
            }
            res.push_back(temp);
        }

        return res;
    }
};