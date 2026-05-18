/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int abs(MountainArray &mountainArr, int s, int e, int t){

        while(s<=e){
            int mid=s+(e-s)/2;

            int c = mountainArr.get(mid);

            if(c == t) return mid;
            else if(c<t) s=mid+1;
            else e=mid-1;
        }

        return -1;
    }

    int dbs(MountainArray &mountainArr, int s, int e, int t){

        while(s<=e){
            int mid=s+(e-s)/2;

            int c = mountainArr.get(mid);

            if(c == t) return mid;
            else if(c<t) e=mid-1;
            else s=mid+1;
        }

        return -1;
    }

    int findPivot(MountainArray &mountainArr){
        int n = mountainArr.length();

        if(mountainArr.get(0) > mountainArr.get(1)) return 0;
        if(mountainArr.get(n-1) > mountainArr.get(n-2)) return n-1;

        int s=1,e=n-2;

        while(s<=e){
            int mid = s+(e-s)/2;
            int l = mountainArr.get(mid-1);
            int c = mountainArr.get(mid);
            int r = mountainArr.get(mid+1);

            if(c>l && c>r) return mid;
            else if(c > l) s=mid+1;
            else e=mid-1;
        }

        return -1; 
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int pivot = findPivot(mountainArr);

        int ans = abs(mountainArr, 0, pivot, target);

        if(ans != -1) return ans;

        return dbs(mountainArr, pivot+1, n-1, target);
    }
};