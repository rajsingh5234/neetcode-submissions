class Solution {
public:

    void solve(vector<int>&nums, vector<int>&temp, vector<int>&mp, vector<vector<int>>&ans){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(mp[i] == 0){
                mp[i] = 1;
                temp.push_back(nums[i]);
                solve(nums, temp, mp, ans);
                temp.pop_back();
                mp[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        vector<int> mp(n, 0);
        solve(nums, temp, mp, ans);
        return ans;
    }
};
