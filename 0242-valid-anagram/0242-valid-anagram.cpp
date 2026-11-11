class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) {
            return false;
        }

        vector<int> temp(26, 0);

        for (int i = 0; i < s.size(); i++) {
            temp[s[i] - 'a']++;
            temp[t[i] - 'a']--;
        }

        for (int num : temp) {
            if (num != 0) {
                return false;
            }
        }
        return true;
    }
};