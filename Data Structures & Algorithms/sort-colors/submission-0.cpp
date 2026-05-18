class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();

        int s=0, mid=0, e=n-1;

        while(mid<=e){
            int v = nums[mid];
            if(v==0){
                swap(nums[s], nums[mid]);
                s++;
                mid++;
            }
            else if(v==1){
                mid++;
            }
            else{
                swap(nums[mid], nums[e]);
                e--;
            }
        }
    }
};