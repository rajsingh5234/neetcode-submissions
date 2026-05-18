class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        vector<int> ans;
        int sum = 0, n;

        for(auto &s : operations){
            bool isNumber = s != "+" && s != "C" && s != "D";

            if(isNumber){
                n = stoi(s);
                ans.push_back(n);
            }

            if(s == "+"){
                int size = ans.size();
                n = ans[size-1] + ans[size-2];
                ans.push_back(n);
            }

            if(s == "C"){
                ans.pop_back();
            }

            if(s == "D"){
                int size = ans.size();
                ans.push_back(ans[size-1]*2);
            }
        }

        for(auto i : ans) sum += i;

        return sum;
    }
};