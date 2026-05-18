class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = speed.size();

        vector<pair<int,int>> arr(n);
        vector<double> st;

        for(int i=0; i<n; i++){
            arr[i] = {position[i], speed[i]};
        }

        sort(arr.begin(), arr.end());

        for(int i=n-1; i>=0; i--){
            double p = arr[i].first;
            double s = arr[i].second;
            st.push_back((target-p)/s);

            int size = st.size();

            if(st.size() >= 2 && st[size-1] <= st[size-2]){
                st.pop_back();
            }
        }

        return st.size();
    }
};
