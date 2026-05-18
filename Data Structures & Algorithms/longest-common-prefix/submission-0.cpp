class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = "";

        string temp = strs[0];

        for(int i=0; i<temp.size(); i++){

            char ch = temp[i];

            for(auto &str : strs){
                if(i >= str.size() || str[i] != ch) return ans;
            }

            ans += ch;
        }

        return ans;
    }
};