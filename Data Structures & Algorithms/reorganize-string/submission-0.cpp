class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";

        unordered_map<char, int> mp;

        for(auto ch : s) mp[ch]++;

        priority_queue<pair<int, char>> pq;

        for(auto &i : mp) pq.push({i.second, i.first});

        while(pq.size() > 1){
            char a = pq.top().second;
            int af = pq.top().first;
            pq.pop();

            char b = pq.top().second;
            int bf = pq.top().first;
            pq.pop();

            ans += a;
            ans += b;

            af--;
            bf--;

            if(af > 0) pq.push({af, a});
            if(bf > 0) pq.push({bf, b});
        }

        if(pq.size() == 1){
            if(pq.top().first > 1) return "";
            ans += pq.top().second;
        }

        return ans;
    }
};