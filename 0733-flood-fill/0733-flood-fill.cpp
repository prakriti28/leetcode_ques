class Solution {

private:
    void dfs(int sr, int sc, int color, int inicolor,vector<vector<int>>& res,
             vector<vector<int>>& image) {

        res[sr][sc] = color;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto dir : directions) {

            int nrow = dir.first + sr;
            int ncol = dir.second + sc;
            if (nrow >= 0 and ncol >= 0 and nrow < image.size() and
                ncol < image[0].size() and image[nrow][ncol]==inicolor
                and res[nrow][ncol]!=color ) {
                    dfs(nrow,ncol,color,image[nrow][ncol],res,image);


            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        vector<vector<int>> res = image;
        int iniColor = image[sr][sc];

        dfs(sr, sc, color, iniColor, res, image);
        return res;
    }
};