class Solution {
public:

    string getKey(string &str){
        string key = "";
        vector<int> mp(26, 0);

        for(auto ch : str){
            mp[ch-'a']++;
        }

        for(int i=0; i<26; i++){
            while(mp[i] > 0){
                key += i+'a';
                mp[i]--;
            }
        }

        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> mp;

        for(auto &s : strs){
            string key = getKey(s);
            mp[key].push_back(s);
        }

        for(auto &i : mp){
            ans.push_back(i.second);
        }

        return ans;
    }
};
