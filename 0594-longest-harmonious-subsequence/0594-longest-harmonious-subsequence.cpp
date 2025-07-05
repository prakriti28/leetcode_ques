class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(int num: nums){
            mp[num]++;
        }

        int mn=INT_MAX;
        int mx=INT_MIN;
        int ln=0;

        for(auto it:mp){
            int num =it.first;
            if(mp.find(num+1)!=mp.end()){
                int count =it.second;
                ln=max(ln,count+mp[num+1]);
                cout<<ln<<endl;

            }

        }
        return ln;
        
    }
};