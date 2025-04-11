class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {

        int n = nums.size();
        long long  sum = 0;
        int mx=INT_MIN;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for (int i = 0; i < n; i++) {
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()){
                mx=max(mx,i-mp[sum-k]);
                
            }
            if(!mp.contains(sum)){
                mp[sum]=i;
            }
           

            
        }
        return mx==INT_MIN ?0:mx;
        
    }
};