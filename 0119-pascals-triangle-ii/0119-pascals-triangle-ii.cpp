class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        for (int i = 1; i <= 34; i++) {
            vector<int> temp;
            for (int j = 1; j <= i; j++) {
                temp.push_back(1);
            }
            res.push_back(temp);
        }

        for (int i = 2; i < res.size(); i++) {
            for (int j = 1; j < res[i].size() - 1; j++) {
                if (i - 1 >= 0 and j - 1 >= 0) {
                    res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
                }
            }
        }
        return res[rowIndex];
    }
}
;