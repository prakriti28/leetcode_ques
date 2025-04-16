class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        int i = 0, j = 0;
        int n = nums.size();
        unordered_map<int, int> mp;

        int cnt = 0;
        long long res = 0;

        while (j < n) {

            cnt += mp[nums[j]];
            mp[nums[j]]++;
            while (cnt >= k) {
                res += n - j;
                cout << i << endl;
                mp[nums[i]]--;
                cnt -= mp[nums[i]];
                i++;
            }

            j++;
        }
        return res;
    }
};