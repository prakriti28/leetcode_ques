class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> prev;

        for (int i = 0; i < numRows; i++) {
            vector<int> cur;
            for (int j = 0; j <= i; j++) {

                if (j == 0 or j == i) {
                    cur.push_back(1);
                } else {
                    cur.push_back(prev[j - 1] + prev[j]);
                }
            }

            prev = cur;
            res.push_back(cur);
        }
        return res;
    }
};