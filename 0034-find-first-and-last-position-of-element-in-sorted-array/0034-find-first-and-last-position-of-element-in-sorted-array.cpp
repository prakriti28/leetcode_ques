class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n=nums.size();
        int start=0;
        int end=n-1;
        int res1=-1;
        int res2=-1;
        vector<int>ans;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                res1=mid;
                end=mid-1;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        ans.push_back(res1);
        start=0;
        end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                res2=mid;
                start=mid+1;
                
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        ans.push_back(res2);
        return ans;
        
    }
};