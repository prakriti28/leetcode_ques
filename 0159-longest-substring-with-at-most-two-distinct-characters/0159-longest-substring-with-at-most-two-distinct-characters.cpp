class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i=0,j=0;
        int n=s.size();
        unordered_map<int,int>mp;
        int mx=INT_MIN;

        while(j<n){
            mp[s[j]]++;

            if(mp.size()<=2){
                mx=max(mx,j-i+1);
            }
            else if(mp.size()>2){
                while(mp.size()>2){
                    mp[s[i]]-=1;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;

                }
            }
            j++;

        }
        return mx;
        
    }
};