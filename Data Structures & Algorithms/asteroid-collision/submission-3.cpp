class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> ans;

        for(auto i : asteroids){
            if(i > 0){
                ans.push_back(i);
            }
            else{
                bool f = 1;
                while(!ans.empty() && ans.back() > 0){
                    int back = ans.back();
                    ans.pop_back();
                    if(back > abs(i)) {
                        ans.push_back(back); 
                        f=0;
                        break;
                    }
                    if(abs(i) == back){
                        f=0;
                        break;
                    }

                    if(abs(i) > back) {
                        continue;
                    }
                }
                if(f) ans.push_back(i);
            }
        }

        return ans;
    }
};