class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string temp = strs[0];
        string ans = "";

        for(int i=0; i<temp.size(); i++){

            char ch = temp[i];

            for(auto str : strs){
                if(i >= str.size()) return ans;
                if(str[i] != ch) return ans;
            }

            ans += ch;
        }

        return ans;
    }
};