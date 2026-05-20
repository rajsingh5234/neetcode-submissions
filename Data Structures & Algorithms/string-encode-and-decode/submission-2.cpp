class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto &str : strs){
            string n = to_string(str.size());
            ans += n;
            ans+='_';
            ans+=str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        int n = s.size();
        vector<string> ans;

        int i = 0;

        while(i < n){
            while(i<n && !isdigit(s[i])) i++;
            if(i >= n) break;

            string cnt = "";
            while(i < n && isdigit(s[i])){
                cnt += s[i];
                i++;
            }
            if(i >= n) break;

            int len = stoi(cnt);

            string curr = "";
            i++;
            while(i < n && len--){
                curr += s[i];
                i++;
            }

            ans.push_back(curr);
            if(i >= n) break;
        }

        return ans;
    }
};
