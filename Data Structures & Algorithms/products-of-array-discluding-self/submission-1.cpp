class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> ans(n);

        left[0] = nums[0];
        for(int i=1; i<n; i++){
            left[i] = nums[i] * left[i-1];
        }

        right[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            right[i] = nums[i] * right[i+1];
        }

        for(int i=0; i<n; i++){
            int l = 1, r = 1;

            if(i-1>=0) l = left[i-1];
            if(i+1<n) r = right[i+1];

            ans[i] = l * r;
        }

        return ans;
    }
};
