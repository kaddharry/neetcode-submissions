class Solution {
   public:
    int flag = 0;
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) {
            flag = 1;
            n = abs(n);
        }

        if (flag == 1) {
            flag = 0;
            return myPow(1/x, n);
        }

        return x * myPow(x, n - 1);
    }
};
