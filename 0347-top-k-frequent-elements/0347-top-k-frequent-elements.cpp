class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for (int num : nums) {

            mp[num]++;
        }
        vector<vector<int>>bucket(n+1);

        for(auto it:mp){
            bucket[it.second].push_back(it.first);
        }

        vector<int>result;

        for(int i=n;i>=1;i--){
            for(int j: bucket[i]){
                result.push_back(j);
                if(result.size()==k){
                    return result;
                }
            }

        }




        return {};
    }
};