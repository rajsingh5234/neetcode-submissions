class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0, ans = n+1;
        int i = 0, j = 0;

        while(j < n){
            sum += nums[j];

            while(sum >= target){
                ans = min(ans, j-i+1);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        if(ans > n) return 0;
        return ans;
    }
};