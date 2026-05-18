class Solution {
public:

    string encode(vector<string>& strs) {

        string ans = "";

        for(auto &s : strs){
            int n = s.size();

            ans += to_string(n);
            ans += '-';
            ans += s;
        }

        return ans;
    }

    vector<string> decode(string s) {

        vector<string> ans;

        string temp = "", size = "";
        int i = 0, n = s.size();

        while(i < n){

            size = "";
            temp = "";

            while(i<n && isdigit(s[i])){
                size += s[i];
                i++;
            }

            int len = stoi(size);
            i++;
            len += i;
            
            while(i<n && i<len){
                temp += s[i];
                i++;
            }

            ans.push_back(temp);

        }

        return ans;
    }
};
