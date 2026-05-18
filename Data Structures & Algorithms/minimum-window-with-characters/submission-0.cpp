class Solution {
public:
    string minWindow(string s, string t) {
        
        string str = "";
        int i=0,j=0,diff=0,n=s.size();
        int ans = n+1, st=-1,e=-1;
        unordered_map<char, int> mp;

        for(auto ch : t) {
            mp[ch]++;
            if(mp[ch] == 1) diff++;
        }

        while(j<n){
            if(mp.count(s[j])){
                mp[s[j]]--;
                if(mp[s[j]] == 0) diff--;
            }

            while(diff == 0){

                if((j-i+1) < ans){
                    ans = j-i+1;
                    st=i;
                    e=j;
                }

                if(mp.count(s[i])){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1) diff++;
                }

                i++;
            }

            j++;
        }

        if(st == -1) return "";

        for(int i=st; i<=e; i++) str += s[i];
        return str;
    }
};
