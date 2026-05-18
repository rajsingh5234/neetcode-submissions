class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        int res;

        for(auto &s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int v2 = st.top();
                st.pop();
                int v1 = st.top();
                st.pop();
                
                if(s=="+") res = v1+v2;
                if(s=="-") res = v1-v2;
                if(s=="*") res = v1*v2;
                if(s=="/") res = v1/v2;
            }
            else{
                res = stoi(s);
            }

            st.push(res);
        }

        return st.top();
    }
};
