class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto &s : tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int v2 = st.top();
                st.pop();
                int v1 = st.top();
                st.pop();
                int res;

                if(s=="+") res = v1+v2;
                if(s=="-") res = v1-v2;
                if(s=="*") res = v1*v2;
                if(s=="/") res = v1/v2;

                st.push(res);
            }
            else{
                int n = stoi(s);
                st.push(n);
            }
        }

        return st.top();
    }
};
