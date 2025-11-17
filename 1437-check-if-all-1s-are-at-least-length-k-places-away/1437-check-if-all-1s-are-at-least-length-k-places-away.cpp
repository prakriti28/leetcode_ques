class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
               int n = nums.size();

        int i = -1;
        int j = 0;
        int count = 0;
        bool flag=false;

        while (j < n) {
            if(nums[j]==1 and i!=-1){
                if((j-i-1)<k){
                    i=j;
                    return false;
                }
            }
            if(nums[j]==1){
                i=j;
            }
            j++;




        }
        return true; 
    }
};