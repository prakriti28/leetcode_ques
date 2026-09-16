class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> str;
        unordered_map<string, vector<string>> mp;
        for (const string&it : strs) {
            string before = it;

            sort(before.begin(), before.end());
            mp[before].push_back(it);
        }

        for (auto it : mp) {
            str.push_back(it.second);
        }

        return str;
    }
};