class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(auto ch : t) mp[ch]++;
        int d = mp.size();
        int n = s.size();
        int i=0,j=0,len=n+1, start;

        while(j < n){
            if(mp.count(s[j])){
                mp[s[j]]--;
                if(mp[s[j]] == 0) d--;
            }

            while(i<n && i<=j && d == 0){

                if(j-i+1 < len){
                    len = j-i+1;
                    start = i;
                }

                if(mp.count(s[i])){
                    mp[s[i]]++;
                    if(mp[s[i]] > 0) d++;
                }

                i++;
            }

            j++;
        }

        if(len > n) return "";
        return s.substr(start, len);
    }
};
