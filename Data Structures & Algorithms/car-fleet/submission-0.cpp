class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        // Store (position, speed)
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort by position (ascending)
        sort(cars.begin(), cars.end());

        // Calculate arrival times
        vector<double> time(n);
        for (int i = 0; i < n; i++) {
            time[i] = (double)(target - cars[i].first) / cars[i].second;
        }

        // Count fleets
        double maxTime = time[n - 1];
        int fleets = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (time[i] > maxTime) {
                fleets++;
                maxTime = time[i];
            }
        }

        return fleets;
    }
};