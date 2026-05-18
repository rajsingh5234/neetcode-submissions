class Solution {
public:

    void solve(vector<int>&nums, int index, vector<vector<int>>&ans){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_set<int> s;

        for(int i=index; i<nums.size(); i++){
            if(s.count(nums[i])) continue;
            s.insert(nums[i]);
            swap(nums[i], nums[index]);
            solve(nums, index+1, ans);
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, 0, ans);
        return ans;
    }
};