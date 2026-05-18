class Solution {
public:

    void solve(string &digits, int index, string &temp, vector<string>&mp, vector<string> &ans){

        if(index >= digits.size()){
            if(!temp.empty()) ans.push_back(temp);
            return;
        }

        int digit = digits[index]-'0';
        string str = mp[digit];

        for(int i=0; i<str.size(); i++){
            temp.push_back(str[i]);
            solve(digits, index+1, temp, mp, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        string temp = "";
        vector<string> ans;
        solve(digits, 0, temp, mp, ans);
        return ans;
    }
};
