class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int n = nums.size();
        int j = n - 1;

        while(i <= j){
            int k = (i + j)/2;
            //cout << k << endl;
            if (nums[k] == target){
                return k;
            }
            if (nums[k] >= nums[i]){
                if (target <= nums[k] && target >= nums[i]){
                    j = k - 1;
                }else {
                    i = k + 1;
                }
            }else{
                if (target >= nums[k] && target <= nums[j]){
                    i = k + 1;
                }else{
                    j = k - 1;
                }
            }
        }
        return -1;
        
    }
};
