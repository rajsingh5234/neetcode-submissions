class Solution {
public:

    bool isValid(vector<int>& weights, int days, int mid){
        int cnt = 1;
        int sum = 0;

        for(auto i : weights){
            sum += i;
            if(sum > mid){
                cnt++;
                sum = i;
                if(cnt > days) return 0;
            }
        }

        return 1;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();

        int s = INT_MIN, e = 0, ans = -1;

        for(auto i : weights){
            s = max(s, i);
            e += i;
        }

        while(s <= e){
            int mid = s + (e-s)/2;

            if(isValid(weights, days, mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        return ans;
    }
};