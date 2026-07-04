class Solution {
   public:
    int maxArea(vector<int>& heights) {
        if(heights.size()==0) return 0;
        int maxArea = INT_MIN;
        int l = 0, r = heights.size() - 1;

        while (l < r) {
            int dist = r - l;
            int eq_h = min(heights[l], heights[r]);
            int area = dist * eq_h;
            maxArea = max(area, maxArea);
            if (heights[l] < heights[r])
                l++;
            else if (heights[l] > heights[r])
                r--;
            else {
                l++;
                r--;
            }
        }
        return maxArea;
    }
};
