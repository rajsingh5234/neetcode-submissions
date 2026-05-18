class KthLargest {
public:

    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> nums;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;

        for(auto i : nums){
            pq.push(i);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};
