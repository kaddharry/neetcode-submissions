class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> suffix(n);
        suffix[n-1] = prices[n-1];
        for(int i = n-2; i >=0; i--){
            suffix[i] = max(prices[i], suffix[i+1]);
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            int profit = suffix[i] - prices[i];
            ans = max(profit,ans);
        }
        return ans;
    }
};
