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

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(0, amount, coins, dp);
    }
};
