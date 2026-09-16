class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
        unordered_map<int,int>mp;
        int mx = INT_MIN;
        int second_mx = INT_MIN;
        for (int num : nums) {

            mp[num]++;
        }

        for(auto it:mp){
            min_heap.push({it.second,it.first});
            if(min_heap.size()>k){
                min_heap.pop();
            }

        }
        vector<int>res;
        while(!min_heap.empty()){
            res.push_back(min_heap.top().second);
            min_heap.pop();


        }
        return res;
    }
};