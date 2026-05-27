class Solution {
public:

    bool isValid(vector<int>&weights, int mid, int days){

        int sum = 0;
        int cnt = 1;

        for(auto i : weights){
            sum += i;
            if(sum > mid){
                cnt++;
                sum = i;
            }
            if(cnt > days) return 0;
        }

        return 1;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        int s = 0, e = 0, ans;

        for(auto i : weights){
            s = max(s, i);
            e += i;
        }

        while(s<=e){
            int mid = s+(e-s)/2;

            if(isValid(weights, mid, days)){
                ans = mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return ans;
    }

    int splitArray(vector<int>& nums, int k) {
        return shipWithinDays(nums, k);
    }
};