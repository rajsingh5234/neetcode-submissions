class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        for(auto i : nums) mp[i]++;

        vector<pair<int,int>> temp;
        for(auto i : mp){
            temp.push_back({i.second, i.first});
        }

        sort(temp.begin(), temp.end());
        vector<int> ans;
        
        while(k--){
            ans.push_back(temp.back().second);
            temp.pop_back();
        }

        return ans;
    }
};
