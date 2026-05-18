class Solution {
public:

    int solve(int i, int t, vector<int>&arr, vector<vector<int>>&dp){
        if(i>=arr.size()) return t == 0;
        if(dp[i][t] != -1) return dp[i][t];

        int include = 0;
        if(arr[i] <= t) include = solve(i, t-arr[i], arr, dp);
        int exclude = solve(i+1, t, arr, dp);

        return dp[i][t] = include + exclude;
    }

    int solveTab(vector<int>&arr, int amount){
        int n = arr.size();

        vector<int> next(amount+1, 0);
        vector<int> curr(amount+1, 0);

        next[0] = 1;

        for(int i=n-1; i>=0; i--){
            for(int t=0; t<=amount; t++){
                int include = 0;
                if(arr[i] <= t) include = curr[t-arr[i]];
                int exclude = next[t];

                curr[t] = include + exclude;
            }
            next = curr;
        }

        return next[amount];
    }

    int change(int amount, vector<int>& coins) {
        return solveTab(coins, amount);
    }
};
