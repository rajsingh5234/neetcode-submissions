class Solution {
public:

    bool solve(vector<int>&nums, int i, int t, int l, int r, int u, int d){
        if(i>=nums.size()) return 1;

        bool op1 = false;
        bool op2 = false;
        bool op3 = false;
        bool op4 = false;

        if(l+nums[i]<=t) op1 = solve(nums,i+1,t,l+nums[i],r,u,d);
        if(r+nums[i]<=t) op2 = solve(nums,i+1,t,l,r+nums[i],u,d);
        if(u+nums[i]<=t) op3 = solve(nums,i+1,t,l,r,u+nums[i],d);
        if(d+nums[i]<=t) op4 = solve(nums,i+1,t,l,r,u,d+nums[i]);

        return op1 || op2 || op3 || op4;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(auto i : matchsticks) sum += i;
        if((sum%4)!=0) return 0;
        int t = sum/4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(matchsticks,0,t,0,0,0,0);
    }
};