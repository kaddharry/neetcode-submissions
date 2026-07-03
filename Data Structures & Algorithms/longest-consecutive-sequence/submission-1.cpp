class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int length = INT_MIN;
        int n = nums.size();
        int temp = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] == 1)
                temp++;
            else if (nums[i] - nums[i - 1] == 0)
                continue;
            else {
                length = max(length, temp);
                temp = 1;
            }
        }
        length = max(length, temp);
        return length;
    }
};
