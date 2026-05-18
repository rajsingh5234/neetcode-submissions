class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();

        unordered_set<char> st;

        int i=0,j=0, ans = 0;

        while(j<n){

            while(i<j && st.count(s[j])){
                st.erase(s[i]);
                i++;
            }
            
            if(!st.count(s[j])){
                st.insert(s[j]);
                ans = max(ans, j-i+1);
            }

            j++;
        }

        return ans;
    }
};
