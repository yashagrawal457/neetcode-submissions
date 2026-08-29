class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> v(n, vector<int>(26,0));

        for(int i = 0; i < n; i++){
            string s = strs[i];
            for(char c: s){
                v[i][c-'a']++;
            }
        }
        map<vector<int>, vector<string>> mp;

        for(int i = 0; i < n; i++){
            mp[v[i]].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }

        return ans;
    }

};
