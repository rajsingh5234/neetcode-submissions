class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0;

        for(auto &i : s){
            if(s.count(i-1)) continue;

            int x = i;
            int cnt = 0;
            while(s.count(x)){
                cnt++;
                x++;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};
