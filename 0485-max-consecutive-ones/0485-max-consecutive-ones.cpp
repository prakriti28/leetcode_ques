class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, res = 0;
        for (int num : nums) {
            if (num == 1) {
                cnt++;
                res = max(cnt, res);

            } else {
                cnt = 0;
            }
        }
        return res;
    }
};