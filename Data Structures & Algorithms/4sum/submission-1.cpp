class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        int n = nums.size();
        int i=0, j, k, l;

        while(i<n){

            l = i+1;

            while(l < n) {
                j=l+1;
                k=n-1;

                while(j<k){
                    double sum = (double)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum == target){
                        ans.push_back({nums[i], nums[l], nums[j],nums[k]});
                        j++;
                        k--;

                        while(j<n && nums[j] == nums[j-1]) j++;
                        while(k>=0 && nums[k] == nums[k+1]) k--;
                    }
                    else if(sum < target){
                        j++;
                        while(j<n && nums[j] == nums[j-1]) j++;
                    }
                    else{
                        k--;
                        while(k>=0 && nums[k] == nums[k+1]) k--;
                    }
                }

                l++;
                while(l<n && nums[l] == nums[l-1]) l++;
            }

            

            i++;
            while(i<n && nums[i] == nums[i-1]) i++;
        }

        return ans;
    }
};