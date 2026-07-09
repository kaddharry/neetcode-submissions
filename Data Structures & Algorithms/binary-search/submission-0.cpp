class Solution {
   public:
    int binary(vector<int>& nums, int target, int l, int r) {
        if (r >= l) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) return binary(nums, target, l, mid-1);
            else return binary(nums,target, mid+1, r);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binary(nums, target, 0, nums.size()-1);
    }
};
