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

    int bs1(MountainArray &mountainArr, int s, int e, int t){
        while(s<=e){
            int mid = s+(e-s)/2;
            int val = mountainArr.get(mid);
            if(val == t) return mid;
            else if(val < t) s=mid+1;
            else e=mid-1;
        }
        return -1;
    }

    int bs2(MountainArray &mountainArr, int s, int e, int t){
        while(s<=e){
            int mid = s+(e-s)/2;
            int val = mountainArr.get(mid);
            if(val == t) return mid;
            else if(val < t) e=mid-1;
            else s=mid+1;
        }
        return -1;
    }

    int findPeak(MountainArray &mountainArr, int n){
        if(n == 1) return 0;
        if(mountainArr.get(0) > mountainArr.get(1)) return 0;
        if(mountainArr.get(n-1) > mountainArr.get(n-2)) return n-1;
        int s = 1, e = n-2;
        while(s<=e){
            int mid = s+(e-s)/2;
            int left = mountainArr.get(mid-1);
            int val = mountainArr.get(mid);
            int right = mountainArr.get(mid+1);
            if(left < val && right < val) return mid;
            else if(val < right) s=mid+1;
            else e=mid-1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = findPeak(mountainArr, n);
        int v1 = bs1(mountainArr, 0, peak, target);
        if(v1 != -1) return v1;
        return bs2(mountainArr, peak+1, n-1, target);
    }
};