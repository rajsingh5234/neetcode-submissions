class Solution {
public:

    void solve(vector<int>&nums, int i, int t, vector<int>&temp, vector<vector<int>>&ans){
        if(t==0){
            ans.push_back(temp);
            return;
        }
        if(i>=nums.size()) return; 

        if(nums[i]<=t){
            temp.push_back(nums[i]);
            solve(nums, i, t-nums[i], temp, ans);
            temp.pop_back();
        }

        solve(nums, i+1, t, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(nums, 0, target, temp, ans);
        return ans;
    }
};
