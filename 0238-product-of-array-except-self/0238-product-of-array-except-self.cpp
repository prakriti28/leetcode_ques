class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix;
        int startPrefix = 1;
        prefix.push_back(1);
        for (int i = 1; i < nums.size(); i++) {
            prefix.push_back(startPrefix * nums[i - 1]);
            startPrefix = startPrefix * nums[i - 1];
        }
        int startSuffix = nums[nums.size() - 1];
        suffix.push_back(1);
        for (int j = nums.size() - 2; j >= 0; j--) {
            suffix.push_back(startSuffix);
            startSuffix = startSuffix * nums[j];
        }
        reverse(suffix.begin(),suffix.end());
        vector<int>res;
        for(int k=0;k<suffix.size();k++){
            res.push_back(suffix[k]*prefix[k]);

        }
        return res;
    }
};