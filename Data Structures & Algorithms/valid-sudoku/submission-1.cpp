class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_set<string> s;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;

                string val(1, board[i][j]);
                string row = val + "i=" + to_string(i);
                string col = val + "j=" + to_string(j);
                string box = val + "i=" + to_string(i/3) + "j=" + to_string(j/3);

                if(s.count(row) || s.count(col) || s.count(box)) return 0;

                s.insert(row);
                s.insert(col);
                s.insert(box);
            }
        }

        return 1;
    }
};
