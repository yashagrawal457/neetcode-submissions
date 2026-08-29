class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> f1(26,0);
        vector<int> f2(26,0);
        int n1 = s1.size();
        int n2 = s2.size();

        if (n1 > n2){
            return false;
        }

        for(int i = 0; i < n1; i++){
            f1[s1[i] - 'a']++;
            f2[s2[i] - 'a']++;
        }
        int matches = 0;
        for(int i = 0; i < 26; i++){
            if(f1[i] == f2[i]){
                matches++;
            }
        }
        if (matches == 26){
            return true;
        }

        for(int i = n1; i < n2; i++){
            if (s2[i-n1] == s2[i]){
                continue;
            }
            f2[s2[i-n1] - 'a']--;
            f2[s2[i] - 'a']++;

            if (f2[s2[i-n1] - 'a'] + 1 == f1[s2[i-n1] - 'a']){
                matches--;
            }else if (f2[s2[i-n1] - 'a'] == f1[s2[i-n1]-'a']){
                matches++;
            }
            
            if (f2[s2[i] - 'a'] - 1 == f1[s2[i] - 'a']){
                matches--;
            }else if (f2[s2[i]-'a'] == f1[s2[i]-'a']){
                matches++;
            }
            
            

            if (matches == 26){
                return true;
            }
        }
        return false;
        
    }
};
