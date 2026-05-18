class Solution {
public:

    void solve(vector<int>& nums, int i, int temp, int &sum){
        if(i >= nums.size()){
            sum += temp;
            return;
        }

        int inc = temp ^ nums[i];
        solve(nums, i+1, inc, sum);

        int exc = temp;
        solve(nums, i+1, temp, sum);
    }

    int subsetXORSum(vector<int>& nums) {
        int sum = 0, temp=0;
        solve(nums, 0, temp, sum);
        return sum;
    }
};