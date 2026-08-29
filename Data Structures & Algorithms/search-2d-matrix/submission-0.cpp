class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0, j = m - 1;

        while(i <= j){
            int mid = i + (j - i)/2;
            cout << i << endl;
            if(matrix[mid][0] <= target && matrix[mid][n-1] >= target){
                int l = 0;
                int r = n - 1;

                while(l <= r){
                    int middle = l + (r-l)/2;
                    if(matrix[mid][middle] == target){
                        return true;
                    }else if (matrix[mid][middle] > target){
                        r = middle - 1;
                    }else{
                        l = middle + 1;
                    }
                }
                return false;
            }else if (target > matrix[mid][n-1]){
                i = mid + 1;
            }else{
                j = mid - 1;
            }
        }
        return false;

    }
};
