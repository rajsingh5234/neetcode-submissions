class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        int i=0,j=0;

        while(j<k && j<n){
            while(!dq.empty() && nums[dq.back()] <= nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }

        if(!dq.empty()){
            ans.push_back(nums[dq.front()]);
        }

        while(j<n){
            i++;
            if(!dq.empty() && i > dq.front()) dq.pop_front();

            while(!dq.empty() && nums[dq.back()] <= nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);

            if(!dq.empty()){
                ans.push_back(nums[dq.front()]);
            }

            j++;
        }

        return ans;
    }
};
