class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();

        for (int i = 0; i < s.size(); i += k) {
            string temp;
            for (int j = i; j < i + k; j++) {
                if (n % k != 0 and temp.size() < k and j > n - 1) {
                    temp.push_back(fill);
                } else {
                    temp.push_back(s[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};