class Solution {
public:

    void solve(vector<int>&nums, int i, vector<int>&temp, vector<vector<int>>&ans, set<vector<int>>&s){
        if(i>=nums.size()){
            if(!s.count(temp)){
                s.insert(temp);
                ans.push_back(temp);
            }
            return;
        }

        temp.push_back(nums[i]);
        solve(nums, i+1, temp, ans, s);
        temp.pop_back();
        solve(nums, i+1, temp, ans, s);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        solve(nums, 0, temp, ans, s);
        return ans;
    }
};
