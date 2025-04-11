class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (auto it : t) {
            mp[it]++;
        }
        int i = 0, j = 0;

        int mn = INT_MAX;
        int cnt = mp.size();
        int start = 0;

        while (j < s.size()) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                    cnt--;
            }
            while (cnt == 0) {
                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if (mp[s[i]] == 1)
                        cnt++;
                }
                if (j - i + 1 < mn) {
                    mn = j - i + 1;
                    start = i;
                }
                i++;
            }
            j++;
        }
        return mn == INT_MAX ? "" : s.substr(start, mn);
    }
};