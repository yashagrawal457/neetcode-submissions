class Solution {
public:
    bool isValidRow(vector<vector<char>>& board, int r){
        unordered_set<char> st;

        for(int i = 0; i < 9; i++){
            if (board[r][i] == '.'){
                continue;
            }
            if (st.find(board[r][i]) != st.end()){
                return false;
            }
            st.insert(board[r][i]);
        }
        return true;
    }
    bool isValidColumn(vector<vector<char>>& board, int r){
        unordered_set<char> st;

        for(int i = 0; i < 9; i++){
            if (board[i][r] == '.'){
                continue;
            }
            if (st.find(board[i][r]) != st.end()){
                return false;
            }
            st.insert(board[i][r]);
        }
        return true;
    }

    bool isValidBox(vector<vector<char>>& board){
        for(int i = 0; i < 7; i+=3){
            for(int j = 0; j < 7; j+=3){
                int x = i, y = j;
                unordered_set<int> st;
                for(int a = x; a < x + 3; a++){
                    for(int b = y; b < y + 3; b++){
                        if (board[a][b] == '.'){
                            continue;
                        }
                        if (st.find(board[a][b]) != st.end()){
                            return false;
                        }
                        st.insert(board[a][b]);
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        if (!isValidBox(board)){
            cout << "hello" << endl;
            return false;
        }
        for(int i = 0; i < 9; i++){
            if (!isValidRow(board,i) || !isValidColumn(board,i)){
                return false;
            }
        }
        return true;
    }
};
