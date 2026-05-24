class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        unordered_map<char, int> mp;
        int i=0, j=0, ans=0;

        while(j<n){
            mp[s[j]]++;

            while(mp[s[j]] > 1){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }

            if(mp.size() > ans){
                ans = mp.size();
            }
            
            j++;
        }
        
        return ans;
    }
};
