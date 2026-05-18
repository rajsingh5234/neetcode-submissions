class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());

        int i=0;
        long long time = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        while(!pq.empty() || i < n){

            if(pq.empty() && tasks[i][0] > time){
                time = tasks[i][0];
            }

            while(i < n && tasks[i][0] <= time){
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            ans.push_back(pq.top().second);
            time += pq.top().first;
            pq.pop();
        }

        return ans;
    }
};