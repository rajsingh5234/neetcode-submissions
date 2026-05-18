class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> ans;

        for(auto i : asteroids){
            if(i > 0 || ans.empty() || ans.back() < 0){
                ans.push_back(i);
            }
            else{
                while(!ans.empty() && ans.back() > 0 && abs(i) > ans.back()){
                    ans.pop_back();
                }
                if(!ans.empty() && ans.back() > 0 && abs(i) == ans.back()){
                    ans.pop_back();
                    continue;
                }
                if(ans.empty() || ans.back() < 0) ans.push_back(i);
            }
        }

        return ans;
    }
};