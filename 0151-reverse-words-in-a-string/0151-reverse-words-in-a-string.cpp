class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int j = n - 1;
        string result;

        while (j >= 0) {
            while (j >= 0 && s[j] == ' ') j--;
            if (j < 0) break;
            int end = j;
            while (j >= 0 && s[j] != ' ') j--;
            int start = j + 1;
            if (!result.empty()) result += " ";
            result += s.substr(start, end - start + 1);
        }

        return result;
    }
};
