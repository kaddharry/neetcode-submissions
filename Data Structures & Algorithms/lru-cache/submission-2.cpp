class LRUCache {
public:
    vector<pair<int,int>> cache;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        int i = 0;
        for(auto x: cache){
            if(x.first == key){
                auto temp = x;
                cache.erase(cache.begin()+i);
                cache.push_back(temp);
                return temp.second;
            }
            i++;
        }
        return -1;
    }
    
    void put(int key, int value) {
        int i = 0;
        for(auto x: cache){
            if(x.first == key){
                cache.erase(cache.begin()+i);
                break;
            }
            i++;
        }
        cache.push_back({key,value});
        if(cache.size() > cap){
            cache.erase(cache.begin());
        }
    }
};
