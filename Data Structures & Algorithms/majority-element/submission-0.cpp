class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();

        int cnt = 0, ele;

        for(auto i : nums){
            if(cnt == 0){
                ele = i;
                cnt = 1;
            }
            else if(i == ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        return ele;
    }
};