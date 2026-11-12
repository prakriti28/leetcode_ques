class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        unordered_map<int, vector<int>> mp;

        int degree = 0;
        int len = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto it : mp) {

            int freq = it.second.size();

            if (freq > degree) {
                degree = freq;

                int last = it.second.back();
                int first = it.second.front();

                int diff = last - first + 1;
                len = diff;
            }
            else if (freq == degree) {

                int last = it.second.back();
                int first = it.second.front();

                int diff = last - first + 1;
                len = min(len, diff);
            }
        }

        return len;
    }
};