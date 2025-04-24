class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        unordered_set<int> st;
        for (auto it : nums) {
            st.insert(it);
        }

        int i = 0;
        int j = 0;

        int n = nums.size();
        unordered_map<int, int> mp;
        int cnt = 0;

        while (j < n) {
            mp[nums[j]]++;



                while (mp.size() ==(st.size())) {
                    cnt+=n-j;
                    mp[nums[i]] -= 1;
                    if (mp[nums[i]] == 0) {
                        mp.erase(nums[i]);
                    }
                    i++;
                }
            
            j++;
        }
        return cnt;
    }
};