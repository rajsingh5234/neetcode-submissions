class Solution {
public:
    string decodeString(string s) {
        
        stack<string> st;

        for(auto ch : s){
            if(ch != ']'){
                string temp = "";
                temp += ch;
                st.push(temp);
                continue;
            }

            string temp = "";
            while(!st.empty() && st.top()[0] != '['){
                temp += st.top();
                st.pop();
            }
            st.pop();

            string digits = "";

            while(!st.empty() && isdigit(st.top()[0])){
                digits += st.top();
                st.pop();
            }

            reverse(digits.begin(), digits.end());

            int n = stoi(digits);

            string res = "";

            while(n--) res += temp;

            st.push(res);
        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};