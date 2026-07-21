class Solution {
public:
    int flag = 0;
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0) flag = 1;

        n = abs(n);

        if(flag == 1) return (1/x)*myPow(x,n-1);
        
        return x*myPow(x, n-1);
    }
};
