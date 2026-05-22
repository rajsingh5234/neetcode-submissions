class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string ans = "";
        int n = word1.size(), m = word2.size();
        int i=0, j=0;
        
        while(i<n || j<m){
            char ch1 = '-', ch2 = '-';
            if(i<n) ch1 = word1[i];
            if(j<m) ch2 = word2[j];

            if(ch1 != '-') ans += ch1;
            if(ch2 != '-') ans += ch2;

            if(i<n) i++;
            if(j<m) j++;
        }

        return ans;
    }
};