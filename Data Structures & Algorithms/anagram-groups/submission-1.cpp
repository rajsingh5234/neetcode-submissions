class Solution {
public:

    string getKey(string &s){
        string ans="";

        vector<int> mp(26, 0);

        for(auto ch : s){
            mp[ch-'a']++;
        }

        for(int i=0; i<26; i++){
            char ch = i+'a';
            int cnt = mp[i];
            while(cnt--){
                ans += ch;
            }
        }

        return ans;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> mp;

        for(auto &str: strs){
            string key = getKey(str);
            mp[key].push_back(str);
        }

        for(auto &i : mp){
            ans.push_back(i.second);
        }

        return ans;
    }
};
