class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;

        int j = 0;
        int maxi = 0;

        for(int i = 0; i < s.length(); i++){
            if(mp.find(s[i]) != mp.end()){
                j = max(j,mp[s[i]] + 1);
            }
            
            maxi = max(maxi, i - j + 1);
            mp[s[i]] = i;

        }
        

        return maxi;
        
        
    }
};
