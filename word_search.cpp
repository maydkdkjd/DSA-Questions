class Solution {
private:
    bool dfs(string word, vector<vector<char>>& board, int row, int col,
            int m, int n, int len, int pos, vector<vector<bool>>& visited, int dx[], int dy[]) {
        if (pos == len - 1) {
            // All characters of the word are found.
            return true;
        }

        // Explore in all four directions.
       
        for (int i = 0; i < 4; i++) {
            int drow = row + dx[i];
            int dcol = col + dy[i];

            if (drow >= 0 && drow < m && dcol >= 0 && dcol < n &&
                !visited[drow][dcol] && board[drow][dcol] == word[pos + 1]) {
                visited[drow][dcol] = true; // Mark the cell as visited.

                if (dfs(word, board, drow, dcol, m, n, len, pos + 1, visited, dx, dy)) {
                    // If the rest of the word is found in any direction, return true.
                    return true;
                }

                visited[drow][dcol] = false; // Backtrack: mark the cell as not visited.
            }
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
         int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    // Start DFS from each cell where the first character matches.
                    visited[i][j] = true; // Mark the cell as visited.
                    if (dfs(word, board, i, j, m, n, word.length(), 0, visited, dx, dy)) {
                        return true;
                    }
                    visited[i][j] = false; // Backtrack: mark the cell as not visited.
                }
            }
        }

        return false;
    }
};
