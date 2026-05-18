class FreqStack {
public:

    unordered_map<int, stack<int>> fl;
    unordered_map<int, int> mp;
    int maxi;

    FreqStack() {
        maxi = 0;
    }
    
    void push(int val) {
        mp[val]++;
        maxi = max(maxi, mp[val]);
        fl[mp[val]].push(val);
    }
    
    int pop() {
        if(fl[maxi].empty()) maxi--;
        int top = fl[maxi].top();
        fl[maxi].pop();
        mp[top]--;
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */