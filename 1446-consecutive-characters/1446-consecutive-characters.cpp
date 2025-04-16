class Solution {
public:
    int maxPower(string s) {
        int i=0,j=0;
        int n=s.size();


        int mx=INT_MIN;

        while(j<n){

            if(s[i]!=s[j]){
                i++;
                continue;
            }
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
        
    }
};