class Solution {
public:

    bool find(int r, int c, vector<vector<char>>&board){
        unordered_set<char> s;

        for(int i=r; i<r+3; i++){
            for(int j=c; j<c+3; j++){
                char v = board[i][j];
                if(v == '.') continue;
                if(s.count(v)) return 0;
                s.insert(v);
            }
        }

        return 1;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_set<string> s;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char v = board[i][j];
                if(v == '.') continue;

                string val(1, v);
                string r = "r-" + to_string(i) + "-" + val;
                string c = "c-" + to_string(j) + "-" + val;

                if(s.count(r) || s.count(c)) return 0;

                s.insert(r);
                s.insert(c);
            }
        }

        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                if(!find(i, j, board)) return 0;
            }
        }

        return 1;
    }
};
