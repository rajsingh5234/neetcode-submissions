class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0, cnt = 0;
        int total = (n+m)/2;
        int prev = 0, curr = 0;

        while(i<n || j<m){
            if(cnt > total) break;
            if(i<n && j<m){
                if(nums1[i]<nums2[j]){
                    prev = curr;
                    curr = nums1[i];
                    i++;

                }
                else{
                    prev = curr;
                    curr = nums2[j];
                    j++;
                }
                cnt++;
            }
            else if(i<n && j>=m){
                prev = curr;
                curr = nums1[i];
                i++;
                cnt++;
            }
            else if(j<m && i>=n){
                prev = curr;
                curr = nums2[j];
                j++;
                cnt++;
            }
        }

        if((n+m) & 1) return curr;
        return (prev + curr) / 2.0;
    }
};
