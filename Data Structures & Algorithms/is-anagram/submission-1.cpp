class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return 0;

        int n = s.size();
        
        vector<int> mp(26, 0);

        for(int i=0; i<n; i++){
            mp[s[i]-'a']++;
            mp[t[i]-'a']--;
        }

        for(auto i : mp){
            if(i != 0) return 0;
        }

        return 1;
    }
};
