class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int carry = 1;
        int n = nums.size();
        for(int i = n-1; i >= 0; i--){
            if(carry == 0) break;
            if(carry == 1){
                nums[i] += carry;
                carry = nums[i]/10;
                nums[i] %= 10;
            }
        }
        if(carry == 1) nums.insert(nums.begin(), carry);
        return nums;
    }
};
