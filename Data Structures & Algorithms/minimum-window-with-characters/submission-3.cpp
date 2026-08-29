class Solution {
public:


    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(char c: t){
            mp[c]++;
        }
        int n = s.size();
        int start = 0;
        int len = n+1;
        int index = -1;
        int count = 0;
        unordered_map<char,int> mp2;
        for(int i = 0; i < n; i++){
            if (mp.find(s[i]) == mp.end()){
                continue;
            }
            mp[s[i]]--;
            if (mp[s[i]] == 0){
                count++;
            }
            //cout << i << " " << count << endl;

            while(count == mp.size()){
                //cout << i << endl;
                //len = min(len,i - start + 1);
                if (i - start + 1 < len){
                    len = i - start + +1;
                    index = start;
                }
                if(mp.find(s[start]) == mp.end()){
                    start++;
                    continue;
                }
                mp[s[start]]++;
                if(mp[s[start]] > 0){
                    count--;
                }
                start++;
            }
        }

        return len == n + 1? "" : s.substr(index,len);
    }
};
