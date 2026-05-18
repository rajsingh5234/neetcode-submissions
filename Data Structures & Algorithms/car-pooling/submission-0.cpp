class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        int n = trips.size();

        sort(trips.begin(), trips.end(), [](vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        });

        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        int currPassengers = 0;

        for(int i=0; i<n; i++){

            auto &trip = trips[i];
            int numPassengers = trip[0];
            int start = trip[1];
            int end = trip[2];

            while(!pq.empty() && pq.top().first <= start){
                currPassengers -= pq.top().second;
                pq.pop();
            }

            currPassengers += numPassengers;
            if(currPassengers > capacity) return 0;

            pq.push({end, numPassengers});
        }

        return 1;
    }
};