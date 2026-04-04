class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int columns = encodedText.size() / rows;

        string res;

        vector<vector<char>> met(rows, vector<char>(columns, ' '));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                met[i][j] = encodedText[columns * i + j];
            }
        }

        for (int r = 0; r < columns; r++) {
            int i = 0;
            int j = r;
            while (i < rows && j < columns) {
                res.push_back(met[i][j]);
                i++;
                j++;
            }
        }

        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};