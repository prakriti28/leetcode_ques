class Solution {
public:
    bool isPalindrome(string s) {

        string t;

        for (char ch : s) {
            if (('a' <= ch and ch <= 'z') or ('0' <= ch and ch <= '9')) {

                t.push_back(ch);
            } else if ('A' <= ch and ch <= 'Z') {
                t.push_back(ch + 32);
            }
        }

        int n = t.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            if (t[i] != t[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};