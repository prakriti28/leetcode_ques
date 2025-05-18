class Solution {

    set<vector<int>> st;

private:
    void helper(int ind, vector<int> in, vector<int> op, int target) {
        if (target == 0) {
            st.insert(op);
            return;
        }
        if (ind == in.size() or target < 0)
            return;
        for (int i = ind; i < in.size(); ++i) {
            if (i > ind && in[i] == in[i - 1])
                continue;

            if (in[i] > target)
                break;

            op.push_back(in[i]);
            helper(i + 1, in, op, target - in[i]);
            op.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> op;
        sort(candidates.begin(), candidates.end());

        helper(0, candidates, op, target);
        vector<vector<int>> res;

        for (auto it : st) {
            res.push_back(it);
        }
        return res;
    }
};