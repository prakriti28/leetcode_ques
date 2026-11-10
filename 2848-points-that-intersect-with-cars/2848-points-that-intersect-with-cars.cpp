class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {

        map<int, int> line;
        for (auto& p : nums) {
            line[p[0]]++;
            line[p[1]+1]--;
        }
        int count = 0;
        int ans = 0;
        int prev=-1;
        for (auto i : line) {
            if (count > 0) {
                ans += i.first - prev;
            }
            count +=i.second;
            prev=i.first;
        }

        return ans;
    }
};