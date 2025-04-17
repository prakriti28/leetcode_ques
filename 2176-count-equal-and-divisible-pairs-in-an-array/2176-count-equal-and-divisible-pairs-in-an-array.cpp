class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int res=0;
        for(auto it:mp){
            for(int i=0;i<it.second.size();i++){
                for(int j=i+1;j<it.second.size();j++){
                    if(it.second[i]*it.second[j]%k==0){
                        res++;

                    }
                }
            }
        }
        return res;
        
    }
};