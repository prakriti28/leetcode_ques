class Solution {
    // private:

    //     int getNonFreqElem(string &s){
    //         unordered_map<char,int>mp;

    //         for(auto it:s){
    //             mp[it]++;
    //         }
    //         char freqElem;
    //         int freq=INT_MIN;
    //         for(auto elem:mp){
    //             if(freq<elem.second){
    //                 freqElem=elem.first;
    //                 freq=max(freq,elem.second);
    //             }
    //         }
    //         return s.size()-freq;
    //     }
    // public:
    //     int characterReplacement(string s, int k) {

    //         int cnt=0;
    //         int freq;
    //         int mxLen=INT_MIN;
    //         for(int i=0;i<s.size();i++){
    //             for(int j=1;j<=s.size()-i;j++){
    //                 string temp=s.substr(i,j);
    //                 freq=getNonFreqElem(temp);
    //                 if(freq<=k){
    //                     int size=temp.size();
    //                     mxLen=max(mxLen,size);

    //                 }

    //             }
    //         }
    //         return mxLen;

    //     }
    // };
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        int mxFreq = 0;

        while (j < s.size()) {
            mp[s[j]]++;
            mxFreq = max(mxFreq, mp[s[j]]);

            if (j - i + 1 - mxFreq > k) {
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);

            j++;
        }

        return ans;
    }
};