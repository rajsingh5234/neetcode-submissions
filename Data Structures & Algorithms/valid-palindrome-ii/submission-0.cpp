class Solution {
public:

    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }

    bool validPalindrome(string s) {
        
        int n = s.size();
        int i=0, j=n-1;

        while(i<=j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                bool op1 = isPalindrome(s, i+1, j);
                if(op1) return 1;
                return isPalindrome(s, i, j-1);
            }
        }

        return 1;
    }
};