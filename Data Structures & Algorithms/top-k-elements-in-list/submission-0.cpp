class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;

        unordered_map<int, int> mp;

        for(auto i : nums) mp[i]++;

        vector<pair<int, int>> temp;

        for(auto &i : mp){
            temp.push_back({i.second, i.first});
        }

        sort(temp.rbegin(), temp.rend());

        int i = 0;

        while(i < k && i < temp.size()){
            ans.push_back(temp[i].second);
            i++;
        }

        return ans;
    }
};
