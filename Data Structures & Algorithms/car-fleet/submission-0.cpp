class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       vector<pair<int,int>> v;
       int n = position.size();
       for(int i = 0; i < n; i++){
        v.push_back({position[i], speed[i]});
       } 
       sort(v.begin(), v.end(), [](pair<int,int> &a, pair<int,int> &b){
        if (a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;
       });
       
       double time;
       stack<double> st; 
       for(int i = 0; i < n; i++){
        time = (target - v[i].first)/(double)v[i].second;
        if (st.empty() || time > st.top()){
            st.push(time);
        }
       }
       return st.size();

       

    }
};
