class Solution {
public:

    bool isValid(vector<vector<char>>& board, int i, int j){
        int n = board.size();
        int m = board[0].size();

        if(i<0 || i>=n || j<0 || j>=m) return 0;
        return 1;
    }

    bool solve(vector<vector<char>>& board, string &word, int index, int i, int j){
        int n = word.size();
        if(!isValid(board, i, j)) return 0;
        if(index == n-1 && word[index] == board[i][j]) return 1;
        if(word[index] != board[i][j]) return 0;

        board[i][j] = '.';

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};

        for(int k=0; k<4; k++){
            bool ans = solve(board, word, index+1, i+dx[k], j+dy[k]);
            if(ans) return 1;
        }

        board[i][j] = word[index];

        return 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(word[0] == board[i][j]){
                    bool ans = solve(board, word, 0, i, j);
                    if(ans) return 1;
                }
            }
        }

        return 0;
    }
};
