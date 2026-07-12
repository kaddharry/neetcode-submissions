class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                // Minimum is in the right half
                l = mid + 1;
            } else {
                // Minimum is at mid or in the left half
                r = mid;
            }
        }

        return nums[l];
    }
};