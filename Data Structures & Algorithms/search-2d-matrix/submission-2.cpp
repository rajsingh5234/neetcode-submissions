class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(), m = matrix[0].size();
        int total = n * m;

        int s=0, e=total-1;

        while(s<=e){
            int mid = s+(e-s)/2;
            int val = matrix[mid/m][mid%m];
            if(val == target) return 1;
            else if(val < target) s=mid+1;
            else e=mid-1;
        }

        return 0;
    }
};
