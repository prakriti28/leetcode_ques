class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0];
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            curr = max(curr, nums[i]);
            if (nums[i] < curr) {
                cnt++;
            }
        }
        return n - cnt;
    }
};