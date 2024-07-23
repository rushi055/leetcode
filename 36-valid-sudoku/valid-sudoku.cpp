class Solution {
public:
    bool validSub(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
        unordered_set<char> st;
        for(int row = sr; row<=er; row++) {
            for(int col = sc; col <= ec; col++) {
                char ch = board[row][col];
                if(ch == '.') continue;
                if(st.count(ch)) return false;
                st.insert(ch);
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        //validate rows
        for(int row = 0; row<9; row++) {
            unordered_set<char> str;
            for(int col = 0; col <9; col++) {
                char ch = board[row][col];
                if(ch == '.') continue;
                if(str.count(ch)) return false;
                str.insert(ch);
            }
        }
        
        //validate columns
        for(int col = 0; col<9; col++) {
            unordered_set<char> stc;
            for(int row = 0; row <9; row++) {
                char ch = board[row][col];
                if(ch == '.') continue;
                if(stc.count(ch)) return false;
                stc.insert(ch);
            }
        }
        
		//validate ech 3*3 box
        // we are iterating in each 3*3 box manually and then validating box 
        for(int sr = 0; sr < 9; sr+=3) {
            int er = sr+2;
            for(int sc = 0; sc < 9; sc+=3) {
                int ec = sc+2;
                if(!validSub(board, sr, er, sc, ec))
                    return false;
            }
        }
        
        return true;
    }
};

//Approch 2
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        
        for(int i = 0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(board[i][j] == '.') continue;
                
                string row = string(1, board[i][j]) + "_row_" + to_string(i);
                string col = string(1, board[i][j]) + "_col_" + to_string(j);
                string box = string(1, board[i][j]) + "_box_" + to_string(i/3) + "_" + to_string(j/3);
                if(st.count(row) || st.count(col) || st.count(box)) return false;
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        
        return true;
    }
};
