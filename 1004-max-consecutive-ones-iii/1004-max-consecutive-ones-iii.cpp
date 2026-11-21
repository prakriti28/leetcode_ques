class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();
        int i = 0, j = 0;
        int cnt1 = 0, cnt0 = 0;
        int res = 0;

        while (j < n) {
            if (nums[j] == 1) {
                cnt1++;

            } else {
                cnt0++;
            }

            if (cnt0 <= k) {
                res = max(cnt1 + cnt0, res);
            } 
            while(cnt0>k) {
                if (nums[i] == 1) {
                    cnt1--;
                }
                else{
                    cnt0--;
                }
                i++;
            }

            j++;
        }
        return res;
    }
};