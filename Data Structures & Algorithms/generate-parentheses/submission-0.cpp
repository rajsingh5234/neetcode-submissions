class Solution {
public:

    void solve(int o, int c, string &temp, vector<string>&ans){
        if(o == 0 && c == 0){
            ans.push_back(temp);
            return;
        }

        if(o > 0){
            temp += '(';
            solve(o-1, c, temp, ans);
            temp.pop_back();
        }

        if(o < c){
            temp += ')';
            solve(o, c-1, temp, ans);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        int o = n, c = n;
        solve(o, c, temp, ans);
        return ans;
    }
};
