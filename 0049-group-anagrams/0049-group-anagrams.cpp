class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> str;
        unordered_map<string, vector<string>> mp;
        for (auto it : strs) {
            string before = it;

            sort(it.begin(), it.end());
            mp[it].push_back(before);
        }

        for (auto it : mp) {
            cout<<it.first<<endl;

            str.push_back(it.second);
        }

        return str;
    }
};