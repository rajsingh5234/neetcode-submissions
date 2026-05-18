class LRUCache {
public:

    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }

    void makeRecent(int key){
        int v = mp[key].second;

        dll.erase(mp[key].first);

        dll.push_front(key);

        mp[key].first = dll.begin();
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        int v = mp[key].second;

        makeRecent(key);

        return v;
    }
    
    void put(int key, int value) {

        if(mp.count(key)){
            mp[key].second = value;
            makeRecent(key);
        }
        else{
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
        }

        if(dll.size() > n){
            int k = dll.back();
            mp.erase(k);
            dll.pop_back();
        }


    }
};
