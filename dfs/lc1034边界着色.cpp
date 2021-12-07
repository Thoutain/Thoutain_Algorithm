class Solution {
public:
    vector<vector<int>> g;
    vector<vector<int>> st;
    int n, m;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    void dfs(int x, int y) {
        bool is_border = false;
        for (int i = 0; i < 4; i ++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] == g[x][y]) {
                if (!st[a][b]) {
                    st[a][b] = 1;
                    dfs(a, b);
                }
            } else {
                is_border = true;
            }
        }

        if (is_border) st[x][y] = 2;
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        g = grid;
        n = g.size(), m = g[0].size();
        st = vector<vector<int>>(n, vector<int>(m));

        st[row][col] = 1;
        dfs(row, col);

        for (int i = 0; i < n; i ++) 
            for (int j = 0; j < m; j ++)
                if (st[i][j] == 2)
                    grid[i][j] = color;

        return grid;
    }
};