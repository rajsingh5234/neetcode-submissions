class Solution {
public:

    void merge(int s, int mid, int e, vector<int>&nums){
        int i = s;
        int j = mid+1;
        vector<int> ans;

        while(i <= mid && j<=e){
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

        while(j <= e){
            ans.push_back(nums[j]);
            j++;
        }

        int k = s;

        for(int i=0; i<ans.size(); i++){
            nums[k] = ans[i];
            k++;
        }
    }

    void mergeSort(int s, int e, vector<int>&nums){
        if(s >= e) return;
        int mid = s + (e-s)/2;
        mergeSort(s, mid, nums);
        mergeSort(mid+1, e, nums);
        merge(s, mid, e, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        
        int s = 0, e = nums.size()-1;
        mergeSort(s, e, nums);
        return nums;
    }
};