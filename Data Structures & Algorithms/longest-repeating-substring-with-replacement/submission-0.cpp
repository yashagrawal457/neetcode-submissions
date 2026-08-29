class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        int ans = 0;

        for(char c = 'A'; c <= 'Z'; c++){
            int j = 0;
            int count = 0;
            for(int i = 0; i < n; i++){
                if(s[i] != c){
                    count++;
                }
                while(count > k){
                    if (s[j] != c){
                        count--;
                    }
                    j++;
                }
                ans = max(ans, i - j + 1);
            }
        }
        return ans;
        
    }
};
