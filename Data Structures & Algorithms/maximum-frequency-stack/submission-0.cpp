class FreqStack {
public:

    priority_queue<pair<int,pair<int,int>>> pq;
    unordered_map<int,int> mp;
    int index;

    FreqStack() {
        index = 0;
    }
    
    void push(int val) {
        mp[val]++;
        pq.push({mp[val], {index, val}});
        index++;
    }
    
    int pop() {
        int v = pq.top().second.second;
        pq.pop();
        mp[v]--;
        return v;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */