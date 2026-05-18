class Solution {
public:

    bool check(vector<int> &mp1, vector<int> &mp2){
        for(int i=0; i<26; i++){
            if(mp1[i] != mp2[i]) return 0;
        }

        return 1;
    }

    bool checkInclusion(string s1, string s2) {
        
        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);

        for(auto ch : s1){
            mp1[ch-'a']++;
        }

        int i=0,j=0;
        int n = s1.size(), m=s2.size();

        while(j<n && j<m){
            mp2[s2[j]-'a']++;
            j++;
        }

        if(check(mp1, mp2)) return 1;

        while(j<m){
            mp2[s2[i]-'a']--;
            i++;

            mp2[s2[j]-'a']++;

            if(check(mp1, mp2)) return 1;

            j++;
        }

        return 0;
    }
};
