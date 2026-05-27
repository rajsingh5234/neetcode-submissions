class TimeMap {
public:

    unordered_map<int, unordered_map<string, string>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[timestamp][key] = value;
    }
    
    string get(string key, int timestamp) {
        while(timestamp >= 0){
            if(mp.count(timestamp) && mp[timestamp].count(key)){
                return mp[timestamp][key];
            }
            timestamp--;
        }
        return "";
    }
};
