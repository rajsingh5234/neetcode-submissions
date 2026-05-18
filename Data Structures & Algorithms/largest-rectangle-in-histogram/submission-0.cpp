class Solution {
public:

    vector<int> nsr(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> nsl(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[i] < arr[st.top()]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = nsl(heights);
        vector<int> right = nsr(heights);
        int ans = 0;

        for(int i=0; i<n; i++){
            int area = (right[i] - left[i] - 1) * heights[i];
            ans = max(area, ans);
        }

        return ans;
    }
};
