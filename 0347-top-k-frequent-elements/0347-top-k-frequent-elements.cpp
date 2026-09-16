class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>min_heap;
        unordered_map<int,int>mp;
        for (int num : nums) {

            mp[num]++;
        }

        for(auto it:mp){
            min_heap.push({it.second,it.first});

        }
        vector<int>res;
        while(k>0 and !min_heap.empty()){
            cout<<min_heap.top().second<<endl;
            res.push_back(min_heap.top().second);
            min_heap.pop();
            k--;



        }
        return res;
    }
};