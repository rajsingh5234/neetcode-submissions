class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> store;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) return "";

        auto &vec = store[key];
        int s = 0, e = vec.size() - 1;
        string res = "";

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (vec[mid].first <= timestamp) {
                res = vec[mid].second;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return res;
    }
};
