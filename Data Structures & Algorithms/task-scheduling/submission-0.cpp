class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char, int> mp;

        for(auto i : tasks) mp[i]++;

        priority_queue<pair<int, char>> pq;

        unordered_set<char> s;
        int ans = 0;

        for(auto &i : mp){
            pq.push({i.second, i.first});
        }

        while(!pq.empty()){

            vector<pair<int, char>> temp;

            for(int i=0; i<=n; i++){
                if(pq.empty()) continue;

                char ch = pq.top().second;
                int f = pq.top().first;
                pq.pop();

                if(!s.count(ch)){
                    s.insert(ch);
                    f--;
                }

                if(f > 0) temp.push_back({f, ch});
            }

            for(auto &i : temp){
                pq.push(i);
            }

            int idle = 0;

            if(!pq.empty()) idle = n+1-s.size();

            ans = ans + s.size() + idle;

            s.clear();
        }

        return ans;
    }
};
