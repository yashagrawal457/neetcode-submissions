class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for(int i = 0; i < n - 2; i++){
            if (i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                if (nums[i] + nums[j] + nums[k] == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j + 1 < k && nums[j+1] == nums[j]){
                        j++;
                    }
                    j++;
                    k--;
                }else if (nums[i] + nums[j] + nums[k] < 0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return ans;
        
    }
};
