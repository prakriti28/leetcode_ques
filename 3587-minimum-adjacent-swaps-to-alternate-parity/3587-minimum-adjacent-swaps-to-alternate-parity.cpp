class Solution {
public:
    int helper(vector<int> v) {
        int c = 0;
        for (int i = 0; i < v.size(); i++) {
            c += abs(v[i] - 2 * i);
        }

        return c;
    }
    int minSwaps(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2) {
                odd.push_back(i);
            } else {
                even.push_back(i);
            }
        }
        int c1 = even.size();
        int c2 = odd.size();
        if (abs(c1 - c2) > 1) {
            return -1;
        }

        int ans = INT_MAX;

        if (c1 >= c2)
            ans = min(ans, helper(even));
        if (c2 >= c1)
            ans = min(ans, helper(odd));

        return ans;
    }
};