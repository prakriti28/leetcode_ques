class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        sort(arr.begin(), arr.end());
        int mi = INT_MAX;
        vector<vector<int>> res;

        for (int i = 1; i < arr.size(); i++) {

            if (abs(arr[i] - arr[i - 1]) <= mi) {
                mi = min(mi, abs(arr[i] - arr[i - 1]));
            }
        }

        for(int i=1;i<arr.size();i++){

            vector<int>temp;

            if(abs(arr[i]-arr[i-1])==mi){
                temp.push_back(arr[i-1]);
                temp.push_back(arr[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
};