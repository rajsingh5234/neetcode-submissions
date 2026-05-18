class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        int n = nums.size();
        int i=0, j, k;

        while(i<n){
            j=i+1;
            k=n-1;

            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;

                    while(j<n && nums[j] == nums[j-1]) j++;
                    while(k>=0 && nums[k] == nums[k+1]) k--;
                }
                else if(sum < 0){
                    j++;
                    while(j<n && nums[j] == nums[j-1]) j++;
                }
                else{
                    k--;
                    while(k>=0 && nums[k] == nums[k+1]) k--;
                }
            }

            i++;
            while(i<n && nums[i] == nums[i-1]) i++;
        }

        return ans;
    }
};
