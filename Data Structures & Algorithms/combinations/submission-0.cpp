class Solution {
public:

    void solve(int i, int n, int k, vector<int>&temp, vector<vector<int>>&ans){

        if(i > n){
            if(k == 0){
                ans.push_back(temp);
            }
            return;
        }

        temp.push_back(i);
        solve(i+1, n, k-1, temp, ans);
        temp.pop_back();
        solve(i+1, n, k, temp, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(1, n, k, temp, ans);
        return ans;
    }
};