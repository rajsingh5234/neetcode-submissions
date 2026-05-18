class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        vector<int> ans(k);

        int i=0,j=0,csum=0,sum=INT_MAX,s=-1,e=-1;

        while(j<k && j<n){
            csum += abs(arr[j]-x);
            j++;
        }

        if(csum < sum){
            sum = csum;
            s=i;
            e=j-1;
        }

        while(j<n){
            csum -= abs(arr[i]-x);
            i++;

            csum += abs(arr[j]-x);

            if(csum < sum){
                sum = csum;
                s=i;
                e=j;
            }

            j++;
        }

        for(int i=s; i<=e; i++){
            ans[i-s] = arr[i];
        }

        return ans;
    }
};