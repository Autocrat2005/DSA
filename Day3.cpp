#Leetcode(Q130)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;

        constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        const int m = board.size();
        const int n = board[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (i * j == 0 || i == m - 1 || j == n - 1)
                    if (board[i][j] == 'O') {
                        q.emplace(i, j);
                        board[i][j] = '*';
                    }
        while (!q.empty()) {
            const auto [i, j] = q.front();
            q.pop();
            for (const auto& [dx, dy] : dirs) {
                const int x = i + dx;
                const int y = j + dy;
                if (x < 0 || x == m || y < 0 || y == n)
                    continue;
                if (board[x][y] != 'O')
                    continue;
                q.emplace(x, y);
                board[x][y] = '*';
            }
        }

        for (vector<char>& row : board)
            for (char& c : row)
                if (c == '*')
                    c = 'O';
                else if (c == 'O')
                    c = 'X';
    }
};

#TC and SC both O(mxn)

#LEetcode(Q542)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = p.first + dirs[i];
                int y = p.second + dirs[i + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    ans[x][y] = ans[p.first][p.second] + 1;
                    q.emplace(x, y);
                }
            }
        }
        return ans;
    }

}
;

#TC and SC : O(mxn)
