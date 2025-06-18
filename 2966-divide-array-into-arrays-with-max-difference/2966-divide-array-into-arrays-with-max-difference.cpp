class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (int i = 0; i < nums.size() / 3; i++) {
            vector<int> temp;

            int diff = 0;

            for (int j = 3 * i; j < (3 * (i + 1)); j++) {
                diff = nums[(3 * (i + 1)) - 1] - nums[3 * i];
                if (diff > k)
                    return {};
                temp.push_back(nums[j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};