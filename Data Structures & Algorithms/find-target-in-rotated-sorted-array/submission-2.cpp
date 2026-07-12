class Solution {
   public:
    int StartIndex(vector<int>& nums) {
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

        return l;
    }
    int binarysearch(vector<int>& nums, int target,int l,int r) {
        if (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                return binarysearch(nums, target, mid + 1, r);
            else
                return binarysearch(nums, target, l, mid - 1);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int s1 = StartIndex(nums);
        int r = nums.size()-1;
        if(s1 == 0) return binarysearch(nums,target,0,r);
        int e2 = s1-1;
        int res = binarysearch(nums,target,0,e2);
        if(res != -1) return res;
        return binarysearch(nums,target,s1,r);
    }
};
