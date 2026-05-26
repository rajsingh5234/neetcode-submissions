class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> ans;
        int n = arr.size();
        int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        if(index == n) index--;

        int i = index, j = index;
        int cnt = 1;
        int left = index-1 >= 0 ? arr[index-1] : INT_MAX;
        int right = index+1 < n ? arr[index+1] : INT_MAX;
        int curr = arr[index];

        int currAbs = abs(curr - x);
        int leftAbs = abs(left - x);
        int rightAbs = abs(right - x);

        int mini = min(currAbs, min(leftAbs, rightAbs));

        if(mini == currAbs){
            i = index;
            j = index;
        }
        else if(mini == leftAbs && index-1 >= 0){
            i = index-1;
            j = index-1;
        }
        else if(mini == rightAbs && index+1 < n){
            i = index+1;
            j = index+1;
        }

        while(cnt < k){
            left = i-1 >= 0 ? arr[i-1] : INT_MAX;
            right = j+1 < n ? arr[j+1] : INT_MAX;

            if(abs(left - x) <= abs(right - x) && i-1 >= 0){
                i--;
                cnt++;
                if(cnt == k) break;
            }

            if(abs(right - x) < abs(left - x) && j+1 < n){
                j++;
                cnt++;
                if(cnt == k) break;
            }
        }

        for(int k=i; k<=j; k++){
            ans.push_back(arr[k]);
        }

        return ans;
    }
};