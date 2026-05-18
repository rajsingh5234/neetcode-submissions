class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n = q.size()-1;
        while(n--){
            q.push(q.front());
            q.pop();
        }
        int v = q.front();
        q.pop();
        return v;
    }
    
    int top() {
        int n = q.size()-1;
        while(n--){
            q.push(q.front());
            q.pop();
        }
        int v = q.front();
        q.push(v);
        q.pop();
        return v;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */