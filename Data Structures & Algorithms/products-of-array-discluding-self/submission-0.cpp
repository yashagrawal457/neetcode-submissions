class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1);
        vector<int> right(n,1);

        for(int i = 1; i < n; i++){
            left[i] = nums[i-1]*left[i-1];
            right[n-1-i] = nums[n-i]*right[n-i];
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            if (i == 0){
                ans[i] = right[i];
            }else if (i == n - 1){
                ans[i] = left[i];
            }else{
                ans[i] = left[i]*right[i];
            }
        }
        return ans;
    }
};
