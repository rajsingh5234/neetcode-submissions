class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i=0, ans = n+1;

        while(i < n){
            int ci = nums[i] - 1;
            if(ci < 0 || ci >=n || nums[ci] == nums[i]){
                i++;
            }
            else{
                swap(nums[i], nums[ci]);
            }
        }

        for(int i=0; i<n; i++){
            if(i+1 != nums[i]){
                ans = i+1;
                break;
            }
        }

        return ans;
    }
};