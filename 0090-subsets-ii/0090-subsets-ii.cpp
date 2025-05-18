class Solution {

    set<vector<int>> res;

private:
    void helper(vector<int>nums, vector<int>out) {

        if (nums.size() == 0) {
            res.insert(out);
            return;
        }
        vector<int> op1 = out;
        vector<int> op2 = out;
        op2.push_back(nums[0]);
        nums.erase(nums.begin());
        helper(nums, op1);
        helper(nums, op2);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 0) {
            return ans;
        }
        vector<int> out;
        sort(nums.begin(), nums.end());
        helper(nums, out);
        for (auto it : res) {
            ans.push_back(it);
        }
        return ans;
    }
};