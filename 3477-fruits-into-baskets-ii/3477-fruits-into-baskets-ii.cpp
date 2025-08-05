class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int i = 0, j = 0;

        int n = fruits.size();
        int m = baskets.size();
        int cnt = 0;
        vector<int> visited(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (baskets[j] >= fruits[i] and !visited[j]) {
                    cnt++;
                    visited[j] = 1;
                    break;
                }
            }
            cout << cnt;
        }

        return n - cnt;
    }
};