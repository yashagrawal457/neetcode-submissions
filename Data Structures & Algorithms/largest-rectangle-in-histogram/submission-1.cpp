class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        int ans = 0;
        stack<int> st;
        int n = heights.size();
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int top = st.top();
                st.pop();
                int hor = st.empty() ? i : i - st.top() - 1;
                int ver = heights[top];
                //cout << hor << " " << ver << endl;
                ans = max(ans, hor*ver);
            }
            st.push(i);
        }
        return ans;
    }
};

