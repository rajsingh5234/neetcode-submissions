class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();
        vector<int> mp(26, 0);
        int i=0,j=0,maxf=0, len=0, ans = 0;

        while(j<n){
            mp[s[j]-'A']++;
            maxf = max(maxf, mp[s[j]-'A']);

            if((j-i+1)-maxf > k){
                mp[s[i]-'A']--;
                i++;
            }

            if((j-i+1)-maxf <= k){
                ans = max(ans, j-i+1);
            }

            j++;
        }

        return ans;
    }
};
