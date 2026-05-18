class Solution {
public:
    string reorganizeString(string s) {
        
        vector<int> mp(26, 0);

        for(auto ch : s) mp[ch-'a']++;

        char maxCh;
        int maxi = INT_MIN;

        for(int i=0; i<26; i++){
            if(mp[i] > maxi){
                maxi = mp[i];
                maxCh = i+'a';
            }
        }

        cout<<maxi<<maxCh<<endl;

        int index = 0;

        while(maxi > 0 && index < s.size()){
            s[index] = maxCh;
            maxi--;
            index+=2;
        }

        if(maxi != 0) return "";

        mp[maxCh-'a'] = 0;

        for(int i=0; i<26; i++){
            while(mp[i] > 0){
                index = index >= s.size() ? 1 : index;
                s[index] = i+'a';
                index+=2;
                mp[i]--;
            }
        }

        return s;
    }
};