class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, pair<int,int>>> pq;

        vector<vector<int>> ans;

        for(auto &v : points){
            int x = v[0];
            int y = v[1];
            int key = (x*x) + (y*y);

            pq.push({key, {x,y}});

            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            ans.push_back({x,y});
        }

        return ans;
    }
};
