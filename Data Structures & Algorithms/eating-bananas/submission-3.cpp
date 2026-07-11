class Solution {
private:
    long long timeconsumed(vector<int> &piles, int s){
        //s is speed
        long long time = 0;
        for(int x: piles){
            time += ceil(static_cast<double>(x) / s);
        }
        return time;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //if size if more than h then it means 
        long long sum = 0;
        int max = 0;
        for(int x: piles){
            sum += x;
            if(max < x) max = x;
        }
        if(sum <= h) return 1;
        if(h == piles.size()) return max;
        int l = 1;
        int r = max;
        int res = 1;
        while(l <= r){
            int speed = (l+r)/2;
            long long time = timeconsumed(piles, speed);
            if(time <= h){
                res = speed;
                r = speed-1;
            }
            else{
                l = speed+1;
            }
        }
        return res;

    }
};
