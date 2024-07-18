// class Solution {
// public:
//     vector<vector<string>> result;
//     bool isValid(vector<string>& board, int row, int col) {
//         // look for up
//         for (int i = row; i >= 0; i--) {
//             if (board[i][col] == 'Q')
//                 return false;
//         }

//         // check left diagonal upwards
//         for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
//             if (board[i][j] == 'Q')
//                 return false;
//         }

//         // check right diagonal upwards
//         for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
//             if (board[i][j] == 'Q')
//                 return false;
//         }

//         return true;
//     }
//     void solve(vector<string>& board, int row) {
//         if (row == board.size()) {
//             result.push_back(board);
//             return;
//         }

//         for (int i = 0; i < board.size(); i++) {
//             if (isValid(board, row, i)) {
//                 board[row][i] = 'Q';

//                 solve(board, row + 1);

//                 board[row][i] = '.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         if (n == 0)
//             return {};
//         vector<string> board(n, string(n, '.'));
//         solve(board, 0);

//         return result;
//     }
// };
class Solution {
public:
    vector<vector<string>> result;
    unordered_set<int> cols;
    unordered_set<int> diags;
    unordered_set<int> antiDiags;

    void solve(vector<string>& board, int row, unordered_set<int>& cols,
               unordered_set<int>& diags, unordered_set<int>& antiDiags) {
        if (row == board.size()) {
            result.push_back(board);
            return;
        }

        /*
            For a square (i, j) :
            Diagonally (i-j)      is constant
            Anti diagonally (i+j) is constant

            We can use this to find which square(i, j)
            has a risk of being attacked by another queen
            placed already in 'diagonal', or 'anti-diagonal'
            or 'column'
        */

        for (int col = 0; col < board.size(); col++) {
            int diag_id = row - col;
            int anti_diag_id = row + col;

            if (cols.find(col) != cols.end() ||
                diags.find(diag_id) != diags.end() ||
                antiDiags.find(anti_diag_id) != antiDiags.end())
                continue;

            cols.insert(col);
            diags.insert(diag_id);
            antiDiags.insert(anti_diag_id);
            board[row][col] = 'Q';

            solve(board, row + 1, cols, diags, antiDiags);

            cols.erase(col);
            diags.erase(diag_id);
            antiDiags.erase(anti_diag_id);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if (n == 0)
            return {};
        vector<string> board(n, string(n, '.'));

        int start_row = 0;

        solve(board, start_row, cols, diags, antiDiags);

        return result;
    }
};