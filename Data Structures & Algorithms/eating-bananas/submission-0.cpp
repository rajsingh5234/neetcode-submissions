class Solution {
public:

    bool isValid(vector<int>& piles, int h, int mid){

        int cnt = 0;

        for(auto i : piles){
            cnt += i / mid;
            if(i % mid > 0) cnt++;
            if(cnt > h) return 0;
        }
        return 1;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();

        int s = 1, e = INT_MIN;

        for(auto i : piles) e = max(e, i);

        int ans = -1;

        while(s <= e){
            int mid = s + (e-s)/2;

            if(isValid(piles, h, mid)){
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
