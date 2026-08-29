class Solution {
public:
    bool calculate(vector<int> &piles, int k, long h){
        long count = 0;
        for(int i = 0; i < piles.size(); i++){
            int t = ceil(piles[i]/(double)k);
            count += t;
        }
        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 1e9;
        int ans = 1e9;
        while(l <= r){
            
            int m = l + (r-l)/2;
            cout << m << endl;
            if (calculate(piles,m,h)){
                r = m - 1;
                ans = m;
            }else{
                l = m + 1;
            }
        }
        return ans;

        
    }
};
