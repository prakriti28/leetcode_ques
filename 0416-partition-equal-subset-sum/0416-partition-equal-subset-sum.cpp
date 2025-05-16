class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n=nums.size();
        int sum=0;
        int total;
        for(auto it:nums){
            sum+=it;

        }
        if(sum%2!=0) return false;

        total=sum/2;

        vector<bool>prev(total+1,0),cur(total+1,0);

        prev[0]=cur[0]=true;

        if(nums[0]<=total){
            prev[nums[0]]=true;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=total;j++){
                bool notTake=prev[j];
                bool take=false;
                if(nums[i]<=j){
                    take=prev[total-nums[i]];
                }
                cur[j]=take or notTake;
            }
            prev=cur;
        }
        return prev[total];
    }
};