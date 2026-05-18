class Solution {
public:

    void merge(int s, int mid, int e, vector<int>&nums){
        vector<int> ans;

        int i=s;
        int j=mid+1;

        while(i<=mid && j<=e){
            if(nums[i] < nums[j]){
                ans.push_back(nums[i]);
                i++;
            }
            else{
                ans.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){
            ans.push_back(nums[i]);
            i++;
        }

        while(j<=e){
            ans.push_back(nums[j]);
            j++;
        }

        i = s;
        for(auto v : ans){
            nums[i] = v;
            i++;
        }
    }

    void mergeSort(int s, int e, vector<int>&nums){
        if(s>=e) return;

        int mid = s+(e-s)/2;

        mergeSort(s, mid, nums);
        mergeSort(mid+1, e, nums);

        merge(s, mid, e, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0, n-1, nums);
        return nums;
    }
};