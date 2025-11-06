class Solution {
    int m, n;
    vector<vector<char>> *boardPtr;
    void dfs(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        auto &board = *boardPtr;
        if (board[i][j] != 'O') return;
        board[i][j] = '#';  // mark as safe (not surrounded)
        dfs(i+1, j); dfs(i-1, j); dfs(i, j+1); dfs(i, j-1);
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        m = board.size(); n = board[0].size();
        boardPtr = &board;
        // mark boundary connected 'O's
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(i, 0);
            if (board[i][n-1] == 'O') dfs(i, n-1);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(0, j);
            if (board[m-1][j] == 'O') dfs(m-1, j);
        }
        // flip and restore
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';      // surrounded
                else if (board[i][j] == '#') board[i][j] = 'O'; // safe
            }
        }
    }
};
