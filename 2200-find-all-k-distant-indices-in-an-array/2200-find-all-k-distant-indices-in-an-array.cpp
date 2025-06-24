class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {

        vector<int> temp, res;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                temp.push_back(i);
            }
        }

        for (int i = 0; i < nums.size(); i++) {

            for (int j = 0; j < temp.size(); j++) {

                if (abs(i - temp[j]) <= k and nums[temp[j]] == key) {

                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};