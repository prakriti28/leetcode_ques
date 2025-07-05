class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;

        for (int ar : arr) {
            mp[ar]++;
        }

        int res = INT_MIN;
        for (auto it : mp) {
            if (it.first == it.second) {
                res = max(it.first, res);
            }
        }
        return res == INT_MIN ? -1 : res;
    }
};