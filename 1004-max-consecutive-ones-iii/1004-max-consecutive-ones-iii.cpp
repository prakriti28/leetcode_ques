class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt = 0;

        int i = 0;
        int j = 0;
        int mxFreq = INT_MIN;
        int ans = INT_MIN;

        int n = nums.size();

        while (j < n) {
            if (nums[j] == 1)
                cnt++;
            if ((j - i + 1) - cnt > k) {
                if (nums[i] == 1)
                    cnt--;
                i++;
            }
            ans = max(ans, j - i + 1);

            j++;
        }
        return ans;
    }
};