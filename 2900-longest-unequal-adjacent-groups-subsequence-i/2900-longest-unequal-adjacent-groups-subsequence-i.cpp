class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {

        vector<string> res;
        int index=0;
        for (int i = 0; i < groups.size() - 1; i++) {
            if (groups[i] != groups[i + 1]) {
                res.push_back(words[i]);
                index=i+1;
            }

        }
        res.push_back(words[index]);


        return res;
    }
};