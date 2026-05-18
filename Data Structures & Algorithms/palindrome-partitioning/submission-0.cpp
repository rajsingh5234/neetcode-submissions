class Solution {
public:

    bool isPalindrome(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i] != s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
    
    void solve(string &s, int index, vector<string>&temp, vector<vector<string>>&ans){

        if(index>=s.size()){
            ans.push_back(temp);
            return;
        }

        string str = "";

        for(int i=index; i<s.size(); i++){
            str += s[i];
            if(isPalindrome(str)){
                temp.push_back(str);
                solve(s, i+1, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        solve(s, 0, temp, ans);
        return ans;
    }
};
