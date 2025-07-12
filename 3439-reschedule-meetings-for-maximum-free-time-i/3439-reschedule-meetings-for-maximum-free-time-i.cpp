class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>gaps;
        int n=startTime.size();
        //creating vector of gaps
        gaps.push_back(startTime[0]);
        for(int i=1;i<n;i++){
            gaps.push_back({startTime[i]-endTime[i-1]});
        }
        gaps.push_back(eventTime-endTime[n-1]);

        //sliding window code
        int i=0;
        int j=0;
        int mx=-1;
        int su=0;
        while(j<gaps.size()){
            su+=gaps[j];
            // if(j-i+1<=k){
            //     j+=1;
            // }
            if(j-i+1==k+1){
                mx=max(mx,su);
                su=su-gaps[i];
                i++;
            }
            j++;
        }
        return mx;
        
    }
};