class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> mp(26, 0);

        int maxi = 0;

        for(auto ch : tasks){
            mp[ch-'A']++;
            maxi = max(maxi, mp[ch-'A']);
        }

        int maxFreq = 0;

        for(auto i : mp){
            if(i == maxi) maxFreq++;
        }

        int ans = (maxi-1)*(n+1)+maxFreq;
        int size = tasks.size();

        return max(size, ans);
    }
};
