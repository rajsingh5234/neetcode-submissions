class Solution {
public:

    bool isAlphanumeric(char ch){
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
            return 1;
        }
        return 0;
    }

    bool isPalindrome(string s) {
        
        int n = s.size();
        int i=0, j=n-1;

        while(i<j){
            if(!isAlphanumeric(s[i])){
                i++;
            }
            else if(!isAlphanumeric(s[j])){
                j--;
            }
            else if(tolower(s[i]) == tolower(s[j])){
                i++;
                j--;
            }
            else{
                return 0;
            }
        }

        return 1;
    }
};
