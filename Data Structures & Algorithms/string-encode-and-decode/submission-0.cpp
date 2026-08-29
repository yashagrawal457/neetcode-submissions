class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(int i = 0; i < strs.size(); i++){
            int len = strs[i].size();
            s += to_string(len);
            s += "#";
            s += strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        if (s.size() == 0){
            return {};
        }
        vector<string> ans;
        int i = 0;
        while(i < s.size()){
            int j = i + 1;
            string temp = s.substr(i,1);
            while(j < s.size() && s[j] != '#'){
                temp += s[j];
                j++;
            }
            i = j + 1;
            int len = stoi(temp);
            ans.push_back(s.substr(i, len));
            i = i + len;
        }

        return ans;

    }
};
