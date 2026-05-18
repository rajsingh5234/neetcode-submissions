class Solution {
public:

    int lowerBound(vector<int> &nums, int s, int e, int t){

        if(t<=0) return -1;
        int ans = -1;

        while(s<=e){
            int mid=s+(e-s)/2;

            if(nums[mid]>=t){
                ans = mid;
                e=mid-1;
            }
            else{
                s= mid+1;
            }
        }
        return ans;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1]+nums[i];
        }

        int ans = n+1;

        for(int i=0; i<n; i++){
            int diff = target-nums[i];
            int t = pre[i]+diff;
            int j = lowerBound(pre, i, n-1, t);
            if(j==-1) continue;
            ans = min(ans, j-i+1);
        }

        if(ans > n) return 0;
        return ans;
    }
};