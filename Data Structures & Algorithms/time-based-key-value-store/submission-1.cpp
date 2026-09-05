class TimeMap {
public:
    unordered_map<string,vector<int>> mp;
    unordered_map<int, string> emotions;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(timestamp);
        emotions[timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()){
            return "";
        }
        if (mp[key][0] > timestamp){
            return "";
        }
        int index = upper_bound(mp[key].begin(), mp[key].end(), timestamp) - mp[key].begin();
        int ts = mp[key][0];
        if (index != 0){
            ts = mp[key][index-1];
        }
        return emotions[ts];

    }
};
