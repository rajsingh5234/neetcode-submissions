class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_set<int> s;
        int n = nums.size();
        int i=0,j=0;

        while(j<n && j<=k){
            if(s.count(nums[j])) return 1;
            s.insert(nums[j]);
            j++;
        }

        while(j<n){
            s.erase(nums[i]);
            i++;

            if(s.count(nums[j])) return 1;
            s.insert(nums[j]);

            j++;
        }

        return 0;
    }
};