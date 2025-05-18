class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        vector<int> temp(1000 + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] / 10 == 0) {
                temp[i] = nums[i];
            } else {
                int sum = 0;
                while (nums[i] > 0) {
                    int rem = nums[i] % 10;
                    sum += rem;
                    nums[i] = nums[i] / 10;
                }
                temp[i] = sum;
            }
        }

        int mn = INT_MAX;

        for (int i = 0; i < temp.size(); i++) {
            if (i == temp[i]) {
                mn = min(mn, i);
            }
        }

        return mn == INT_MAX ? -1 : mn;
    }
};