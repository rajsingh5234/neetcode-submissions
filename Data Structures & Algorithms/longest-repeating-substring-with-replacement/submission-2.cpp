class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxi = 0, ans = 0;
        unordered_map<char, int> mp;
        int i=0,j=0;

        while(j<n){
            mp[s[j]]++;
            maxi = max(maxi, mp[s[j]]);

            if((j-i+1) - maxi > k){
                mp[s[i]]--;
                i++;
            }

            if((j-i+1) - maxi <= k){
                ans = max(ans, j-i+1);
            }

            j++;
        }

        return ans;
    }
};
