class Solution {

    set<vector<int>> st;

private:
    void helper(vector<int> in, vector<int> op, int target) {
        if (target == 0) {
            st.insert(op);
            return;
        }
        if (in.size() == 0 or target < 0)
            return;

        int val = in[0];            
        vector<int> in2 = in;
        in.erase(in.begin());    
        if (val <= target) {
            op.push_back(val);
            helper(in2, op, target - val);
            op.pop_back();
        }
        helper(in, op, target);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> op;

        helper(candidates, op, target);
        vector<vector<int>> res;

        for (auto it : st) {
            res.push_back(it);
        }
        return res;
    }
};