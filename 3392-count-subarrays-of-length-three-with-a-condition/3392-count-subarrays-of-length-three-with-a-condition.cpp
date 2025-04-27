class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        while (j < n) {

            if (j - i + 1 == 3) {
                if ((nums[i] + nums[j]) == (0.5 * nums[j - 1])) {
                    cnt++;
                }
                i++;
            }
            j++;
        }
        return cnt;
    }
};