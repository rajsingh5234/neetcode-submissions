class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i=0;
        vector<vector<int>> ans;

        while(i<n){
            int j = i+1, k = n-1;

            while(j < k){
                int sum = nums[i]+nums[k]+nums[j];

                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
                else if(sum < 0){
                    j++;
                    while(j<k && nums[j] == nums[j-1]) j++;
                }
                else{
                    k--;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }

            i++;
            while(i<n && nums[i] == nums[i-1]) i++; 
        }

        return ans;
    }
};
