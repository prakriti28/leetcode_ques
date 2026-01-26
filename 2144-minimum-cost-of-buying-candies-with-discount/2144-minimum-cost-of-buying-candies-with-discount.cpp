class Solution {
public:
    int minimumCost(vector<int>& cost) {

        sort(cost.begin(), cost.end(), greater<int>());

        int totalCost = 0;

        for (int i = 1; i <= cost.size(); i++) {
            if (i % 3 == 0) {
                cout << i << endl;
                continue;
            }
            totalCost += cost[i - 1];
        }

        return totalCost;
    }
};