class Solution {
public:

    bool isValid(vector<int>&nums, int mid, int k){
        int sum = 0, cnt=1;

        for(auto i : nums){
            sum += i;
            if(sum > mid){
                sum = i;
                cnt++;
            }
            if(cnt > k) return 0;
        }

        return 1;
    }

    int splitArray(vector<int>& nums, int k) {
        
        int s = INT_MIN, e=0,ans;
        for(auto i : nums){
            s = max(s, i);
            e += i;
        }

        while(s<=e){
            int mid = s+(e-s)/2;

            if(isValid(nums, mid, k)){
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