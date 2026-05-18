class StockSpanner {
public:

    stack<pair<int,int>> st;
    int index;

    StockSpanner() {
        st.push({INT_MAX, -1});
        index=0;
    }
    
    int next(int price) {
        
        while(st.top().first <= price){
            st.pop();
        }
        int ans = index - st.top().second;
        st.push({price, index});
        index++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */