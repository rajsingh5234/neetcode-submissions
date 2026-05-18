class Solution {
public:

    void solve(string &s, int index, string &temp, vector<string>&ans, unordered_set<string> &st){

        if(index>=s.size()){
            if(!temp.empty()) temp.pop_back();
            ans.push_back(temp);
            return;
        }

        string str = "";

        for(int i=index; i<s.size(); i++){
            str += s[i];
            if(st.count(str)){
                string prev = temp;
                temp += str;
                temp += ' ';
                solve(s, i+1, temp, ans, st);
                temp = prev;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string temp = "";
        unordered_set<string> st;

        for(auto &str : wordDict) st.insert(str);

        solve(s, 0, temp, ans, st);
        return ans;
    }
};