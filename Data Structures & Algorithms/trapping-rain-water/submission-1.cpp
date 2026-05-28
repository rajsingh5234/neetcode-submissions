class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxi = height[0];
        int maxIndex = 0, ans = 0;
        for(int i=0; i<n; i++) {
            if(height[i] > maxi){
                maxi = height[i];
                maxIndex = i;
            }
        }

        int leftmax = height[0];
        int rightmax = height[n-1];

        for(int i=0; i<maxIndex; i++){
            leftmax = max(leftmax, height[i]);
            ans += leftmax - height[i];
        }

        for(int i=n-1; i>maxIndex; i--){
            rightmax = max(rightmax, height[i]);
            ans += rightmax - height[i];
        }

        return ans;
    }
};
