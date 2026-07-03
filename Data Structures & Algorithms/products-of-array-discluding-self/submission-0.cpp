class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroflag = 0;
        long product = 1;
        for (int x : nums) {
            if (x == 0) {
                zeroflag++;
            } else {
                product *= x;
            }
        }
        vector<int> res(nums.size(),0);
        for (int i = 0; i < nums.size(); i++) {
            if(zeroflag > 1) return res;
            else if(zeroflag == 1){
                if(nums[i] != 0) continue;
                res[i] = product;
                return res;
            }
            else{
                res[i] = product/nums[i];
            }
        }
        return res;
    }
};
