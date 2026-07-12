class Solution {
public:
    int StartIndex(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    int binarysearch(vector<int>& nums, int target, int l, int r) {
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivot = StartIndex(nums);
        int n = nums.size();

        // Array is not rotated
        if (pivot == 0)
            return binarysearch(nums, target, 0, n - 1);

        // Target can only lie in the second half
        if (nums[pivot] <= target && target <= nums[n - 1])
            return binarysearch(nums, target, pivot, n - 1);

        // Otherwise, search the first half
        return binarysearch(nums, target, 0, pivot - 1);
    }
};