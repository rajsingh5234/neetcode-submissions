class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        int ans = 0;
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int right = i;
                int left = -1;

                int h = heights[st.top()];
                st.pop();

                if(!st.empty()) left = st.top();

                int area = (right - left - 1) * h;

                ans = max(ans, area);
            }
            st.push(i);
        }

        while(!st.empty()){
            int right = n;
            int left = -1;

            int h = heights[st.top()];
            st.pop();

            if(!st.empty()) left = st.top();

            int area = (right - left - 1) * h;

            ans = max(ans, area);
        }

        return ans;
    }
};
