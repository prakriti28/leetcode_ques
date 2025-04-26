class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        int i = -1;
        int j = 0;
        int n = nums.size();
        int tempMin = -1;
        int tempMax = -1;
        long long ans = 0;

        while (j < n) {
            if (nums[j] < minK || nums[j] > maxK) {
                i = j;
            }
            if (nums[j] == minK) {
                tempMin = j;
            }
            if (nums[j] == maxK) {
                tempMax= j;
            }
            ans+=1ll*max(0,min(tempMin,tempMax)-i);

            j++;
        }
        return ans;
    }
};