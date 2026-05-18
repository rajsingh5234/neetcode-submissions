class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        int n = people.size();
        int i=0, j=n-1;
        int ans = 0;

        while(i<j){
            int sum = people[i]+people[j];

            if(sum <= limit){
                i++;
                j--;
                ans++;
            }
            else{
                ans++;
                j--;
            }
        }

        if(i==j)ans++;

        return ans;
    }
};