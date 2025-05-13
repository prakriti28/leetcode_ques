class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> freq(26, 0);
        const int MOD = 1e9 + 7;

        for (char c : s) {
            freq[c - 'a']++;
        }
        for (int j = 0; j < t; j++) {
            vector<long long> tmp(26, 0);
            for (int i = 0; i < 26; i++) {
                if (char(i + 'a') != 'z') {
                    tmp[i + 1] = (freq[i]) % MOD;
                } else {
                    tmp[0] = (tmp[0] + freq[i]) % MOD;
                    tmp[1] = (tmp[1] + freq[i]) % MOD;
                }
            }
            freq = tmp;
        }
        long long len =0;
        for (long long c : freq) {
            cout << c << endl;
            len+=c;
        }

        return len%MOD;
    }
};