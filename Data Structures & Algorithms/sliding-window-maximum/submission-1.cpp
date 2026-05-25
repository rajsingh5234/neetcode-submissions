class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> q;
        vector<int> ans;

        int n = nums.size();
        int i=0, j=0;

        while(j<k && j<n){
            while(!q.empty() && nums[q.back()] <= nums[j]){
                q.pop_back();
            }
            q.push_back(j);
            j++;
        }

        if(!q.empty()){
            ans.push_back(nums[q.front()]);
        }

        while(j < n){
            i++;
            if(!q.empty() && i > q.front()){
                q.pop_front();
            }

            while(!q.empty() && nums[q.back()] <= nums[j]){
                q.pop_back();
            }
            q.push_back(j);

            if(!q.empty()){
                ans.push_back(nums[q.front()]);
            }

            j++;
        }

        return ans;
    }
};
