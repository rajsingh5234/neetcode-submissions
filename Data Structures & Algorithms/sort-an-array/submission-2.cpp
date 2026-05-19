class Solution {
public:

    int findPivot(int s, int e, vector<int>&nums){
        int pivot = nums[s];
        int j = s;

        for(int i=s; i<=e; i++){
            if(nums[i] <= pivot){
                swap(nums[i], nums[j]);
                j++;
            }
        }

        swap(nums[j-1], nums[s]);
        return j-1;
    }

    void quickSort(int s, int e, vector<int>&nums){
        if(s >= e) return;

        int pivotIndex = findPivot(s, e, nums);

        quickSort(s, pivotIndex-1, nums);
        quickSort(pivotIndex+1, e, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        
        int s = 0, e = nums.size()-1;
        quickSort(s, e, nums);
        return nums;
    }
};