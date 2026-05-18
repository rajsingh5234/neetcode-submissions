class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        
        for(auto ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(st.empty()) return 0;
                if(ch == ')' && st.top() != '(') return 0;
                if(ch == '}' && st.top() != '{') return 0;
                if(ch == ']' && st.top() != '[') return 0;

                st.pop();
            }
        }

        return st.empty();
    }
};
