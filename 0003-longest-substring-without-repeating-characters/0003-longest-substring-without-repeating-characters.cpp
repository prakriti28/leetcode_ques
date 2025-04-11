class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int mx = INT_MIN;

        while (j < s.size()) {
            mp[s[j]]++;
            if (j - i + 1 == mp.size()) {
                mx = max(mx, j - i + 1);
            }

            else if (mp.size() < j - i + 1) {
                while (mp.size() < (j - i + 1)) {
                    mp[s[i]] -= 1;
                    if (mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }

        return mx == INT_MIN ? 0 : mx;
    }
};