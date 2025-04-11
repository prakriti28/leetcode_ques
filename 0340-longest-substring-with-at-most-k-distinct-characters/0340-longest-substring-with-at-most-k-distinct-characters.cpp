class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int i=0,j=0;
        int n=s.size();
        unordered_map<int,int>mp;
        int mx=INT_MIN;

        while(j<n){
            mp[s[j]]++;

            if(mp.size()<=k){
                mx=max(mx,j-i+1);
            }
            else if(mp.size()>k){
                while(mp.size()>k){
                    mp[s[i]]-=1;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;

                }
            }
            j++;

        }
        return mx==INT_MIN? 0: mx;
        
    }
};