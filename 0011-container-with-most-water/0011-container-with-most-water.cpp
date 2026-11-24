class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int l = 0;

        int r = n - 1;
        int area = 0;
        while (l <= r) {
            int len = r - l;
            area = max(area, len * min(height[l], height[r]));

            if (height[l] <= height[r]) {
                l++;
            } else if (height[l] > height[r]) {
                r--;
            }
        }
        return area;
    }
};