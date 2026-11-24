class Solution {
public:
    bool checkString(string s) {
        int flag = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == 'a' and s[i - 1] == 'b') {
                flag = 1;
                break;
            }
        }
        return !flag;
    }
};