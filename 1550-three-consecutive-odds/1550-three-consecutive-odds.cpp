class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i = 0;
        int j = 0;
        int n = arr.size();
        int cnt = 0;

        while (j < n) {
            if (arr[j] % 2 != 0) {
                cnt++;
            }
            if(cnt==3){
                return true;
            }
            if (j - i + 1 == 3) {
                if (arr[i] % 2 != 0)
                    cnt--;
                i++;
            }
            j++;
        }
        return false;
    }
};