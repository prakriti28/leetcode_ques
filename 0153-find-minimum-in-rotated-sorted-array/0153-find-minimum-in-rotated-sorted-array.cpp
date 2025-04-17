class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if (nums[0] <= nums[nums.size()-1]) return nums[0];
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[r])
                r = mid;
            else
                l = mid + 1;
        }
        return nums[l];
    }
};