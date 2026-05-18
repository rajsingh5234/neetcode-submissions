class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> mp(1001, 0);
        int sum = 0;

        for(auto &v : trips){
            mp[v[1]] += v[0];
            mp[v[2]] += -v[0];
        }

        for(auto i : mp){
            sum += i;
            if(sum > capacity) return 0;
        }

        return 1;
    }
};