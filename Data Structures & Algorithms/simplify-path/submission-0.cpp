class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> ans;
        int n = path.size();
        int i=1;

        while(i<n){
            string temp = "";
            while(i<n && path[i]!= '/'){
                temp += path[i];
                i++;
            }

            if(temp.empty() || temp == "."){
                i++;
                continue;
            }
            else if(temp == ".."){
                if(!ans.empty()) ans.pop_back();
            }
            else{
                ans.push_back(temp);
            }

            i++;
        }

        string res = "/";
        for(auto &s : ans){
            res += s;
            res += "/";
        }

        if(res.size() > 1) res.pop_back();
        return res;
    }
};