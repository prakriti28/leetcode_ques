class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < groupSizes.size(); i++) {

            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for (auto it : mp) {

            for (int i = 0; i < it.second.size() / it.first; i++) {
                vector<int> temp;
                for (int j = it.first * i; j < it.first * i + it.first; j++) {
                    temp.push_back(it.second[j]);
                }
                res.push_back(temp);
            }
        }
        return res;
    }
};