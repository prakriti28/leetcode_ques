class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int ans = 0;
        int n=nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int reqSum = nums[i] + nums[j];
                if (reqSum<target) {
                    ans++;
                }
            }
        }
        return ans;
    }
};