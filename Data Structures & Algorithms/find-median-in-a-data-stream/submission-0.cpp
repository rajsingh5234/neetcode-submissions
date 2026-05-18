class MedianFinder {
public:

    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxi.empty() || num <= maxi.top()){
            maxi.push(num);
        }
        else{
            mini.push(num);
        }

        if(mini.size() > maxi.size()){
            maxi.push(mini.top());
            mini.pop();
        }
        else if(maxi.size() > mini.size()+1){
            mini.push(maxi.top());
            maxi.pop();
        }
    }
    
    double findMedian() {
        if(maxi.size() == mini.size()){
            return (maxi.top() + mini.top())/2.0;
        }
        return maxi.top();
    }
};
