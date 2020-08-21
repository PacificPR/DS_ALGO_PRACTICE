/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.     

 */


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (0 == m || 0 == word.size())
            return false;
        int n = board[0].size();
        vector<vector<int>> seen(m, vector<int>(n, 0));
        char fc = word[0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (if( board[i][j] == fc && dfs(board, word, i, j, m, n, seen, 0))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int m, int n, vector<vector<int>>& seen, int start) {
        if (i < 0 || i >= m || j < 0 || j >= n || seen[i][j] || board[i][j] != word[start])
            return false;
        if (start >= word.size() - 1)
            return true;
        seen[i][j] = 1;
        if (dfs(board, word, i + 1, j, m, n, seen, start + 1)
        || dfs(board, word, i - 1, j, m, n, seen, start + 1)
        || dfs(board, word, i, j + 1, m, n, seen, start + 1)
        || dfs(board, word, i, j - 1, m, n, seen, start + 1))
            return true;
        seen[i][j] = 0;
        return false;
    }
};
