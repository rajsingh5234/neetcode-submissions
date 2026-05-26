class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return 0;
        vector<int> temp(256, 0);
        for(auto ch : s1){
            temp[ch]++;
        }

        set<vector<int>> s;
        s.insert(temp);

        vector<int> mp(256, 0);
        int i=0,j=0;

        while(j<s1.size()){
            char ch = s2[j];
            mp[ch]++;
            j++;
        }

        if(s.count(mp)) return 1;

        while(j < s2.size()){
            mp[s2[i]]--;
            i++;

            mp[s2[j]]++;

            if(s.count(mp)) return 1;

            j++;
        }

        return 0;
    }
};
