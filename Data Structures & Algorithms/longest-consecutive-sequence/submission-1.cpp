class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        if (nums.size() == 0){
            return 0;
        }

        for(int k: nums){
            st.insert(k);
        }
        int ans = 1;
        for(int k: st){
            
            int j = k - 1;
            while(st.find(j) != st.end()){
                st.erase(j);
                j--;
                
            }
            int x = k + 1;

            while(st.find(x) != st.end()){
                st.erase(x);
                x++;
            }
            ans = max(x - j - 1,ans);
        }
        return ans;
    }
};
