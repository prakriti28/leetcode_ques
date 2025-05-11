class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int start = 0;
        int mx = 0;
        for (int i = 0; i < gain.size(); i++) {

            start += gain[i];
            mx = max(start, mx);
        }
        return mx;
    }
};