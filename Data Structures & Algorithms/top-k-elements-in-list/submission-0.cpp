class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> mp;

        for(int x:nums) mp[x]++; //created map

        vector<pair<int,int>> vec(mp.begin(), mp.end()); //copies map into vector pair

        sort(vec.begin(), vec.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });
        //sorted the vector pair

        vector<int> res; //inserting top first k elements into res
        for(int i = 0; i < k; i++){
            res.push_back(vec[i].first);
        }
        return res;
    }
};
