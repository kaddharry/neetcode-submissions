class Node {
   public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    Node* left;
    Node* right;
    unordered_map <int, Node*> cache;

    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node){
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if(cache.count(key)){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if(cache.count(key)){
            remove(cache[key]);
        }
        Node* node = new Node(key, value);
        insert(node);
        cache[key] = node;
        if(cap < cache.size()){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
