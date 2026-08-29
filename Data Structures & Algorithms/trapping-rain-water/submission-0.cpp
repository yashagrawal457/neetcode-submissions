class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0;
        

        for(int i = 0; i < height.size(); i++){
            while(!st.empty() && height[i] >= height[st.top()]){
                int k = height[st.top()];
                st.pop();

                if (!st.empty()){
                    int l = st.top();
                    int y = min(height[l], height[i]) - k;
                    int x = i - l - 1;
                    ans += x*y;
                }
            }
            st.push(i);
        }

        return ans;
    }
};
