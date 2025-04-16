class Solution {
public:
    int countHomogenous(string s) {
        int i = 0, j = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        long long res = 0;
        long long mod=1e9+7;

        while (j < n) {

            if (s[i] != s[j]) {
                i++;
                continue;
            }
            res += j - i + 1;
            j++;
        }
        return res%mod;
    }
};