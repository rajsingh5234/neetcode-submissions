class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int lmax = -1, rmax = -1;
        int left = 0, right = n-1;
        int ans = 0;

        while(left <= right){

            if(lmax < rmax){
                if(height[left] >= lmax){
                    lmax = height[left];
                }
                else{
                    ans += lmax - height[left];
                }
                left++;
            }
            else{
                if(height[right] >= rmax){
                    rmax = height[right];
                }
                else{
                    ans += rmax - height[right];
                }
                right--;
            }
        }

        return ans;
    }
};
