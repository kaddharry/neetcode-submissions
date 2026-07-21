class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long num = 0;
        for(int dig: digits){
            num = num*10 + dig;
        }
        num++;
        digits.clear();
        while(num > 0){
            digits.push_back(num%10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
