class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = 0;
        int n = nums.size();
        long long sum = 0;
        int len = 0;

        while (right < n) {

            sum += nums[right];

            while ((long long)nums[right] * (right - left + 1) - sum > k) {
                sum -= nums[left];
                left++;
            }
            len = max(len, right - left + 1);

            right++;
        }
        return len;
    }
};