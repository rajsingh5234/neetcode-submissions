class Solution {
public:

    unordered_set<int> rs;
    unordered_set<int> us;
    unordered_set<int> ds;

    void solve(int col, int n, int &ans){
        if(col >= n){
            ans++;
            return;
        }

        for(int row=0; row<n; row++){
            if(rs.count(row) || us.count(row-col) || ds.count(row+col)){
                continue;
            }

            rs.insert(row);
            us.insert(row-col);
            ds.insert(row+col);
            solve(col+1, n, ans);
            rs.erase(row);
            us.erase(row-col);
            ds.erase(row+col);
        }
    }

    int totalNQueens(int n) {
        int ans = 0;
        solve(0, n, ans);
        return ans;
    }
};