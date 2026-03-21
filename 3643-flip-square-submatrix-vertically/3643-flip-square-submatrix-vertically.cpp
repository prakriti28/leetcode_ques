class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {

        int n = grid.size() - 1;
        vector<vector<int>> temp;
        temp = grid;
        int l = k;
        for (int i = x; i < x + k; i++) {
            for (int j = y; j < y + k; j++) {

                grid[i][j] = temp[x + (k+x-i-1)][j];
            }
            cout << endl;
        }

        return grid;
    }
};