class Solution {
public:

    unordered_set<int> rs;
    unordered_set<int> us;
    unordered_set<int> ds;

    void solve(int col, int n, vector<string>&board, vector<vector<string>>&ans){

        if(col >= n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(rs.count(row) || us.count(row-col) || ds.count(row+col)){
                continue;
            }
            
            rs.insert(row);
            us.insert(row-col);
            ds.insert(row+col);
            board[row][col] = 'Q';
            solve(col+1, n, board, ans);
            rs.erase(row);
            us.erase(row-col);
            ds.erase(row+col);
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n);

        for(int i=0; i<n; i++){
            string s = "";
            for(int j=0; j<n; j++){
                s += '.';
            }
            board[i] = s;
        }

        solve(0, n, board, ans);
        return ans;
    }
};
