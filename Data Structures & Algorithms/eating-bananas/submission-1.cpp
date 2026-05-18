class Solution {
public:

    bool isValid(vector<int>&piles, int mid, int h){

        int sum = 0;

        for(auto i : piles){
            sum += (i / mid);
            if((i % mid)) sum++;
            if(sum > h) return 0;
        }

        return 1;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int s = 1, e = INT_MIN;
        int ans;

        for(auto i : piles) e = max(e, i);

        while(s<=e){
            int mid = s+(e-s)/2;

            if(isValid(piles, mid, h)){
                ans = mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return ans;
    }
};
