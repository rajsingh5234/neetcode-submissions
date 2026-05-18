class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        vector<pair<int,int>> arr;

        int n = profits.size();

        for(int i=0; i<n; i++){
            arr.push_back({capital[i], profits[i]});
        }

        sort(arr.begin(), arr.end());

        priority_queue<int> pq;

        int i = 0;

        while(!pq.empty() || i < n){

            while(i < n && arr[i].first <= w){
                pq.push(arr[i].second);
                i++;
            }

            if(pq.empty()) break;

            int top = pq.top();
            pq.pop();

            w += top;
            k--;
            if(k == 0) break;
        }

        return w;
    }
};