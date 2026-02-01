class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int cost1 = nums[0];
        int cost2 = INT_MAX;
        int cost3 = INT_MAX;

        for (int i = 1; i < nums.size(); i++) {
            if (cost2 > nums[i]) {
                cost3 = cost2;
                cost2 = nums[i];
            } else if (cost3 > nums[i]) {
                cost3 = nums[i];
            }
        }
        return cost1 + cost2 + cost3;
    }
};