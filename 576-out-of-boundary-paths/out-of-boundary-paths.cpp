class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {     

        int MOD = (int)1e9 + 7; 

        vector<vector<int>> grid_1(m+2, vector<int>(n+2, 0));
        vector<vector<int>> grid_2(m+2, vector<int>(n+2, 0));

        vector<vector<int>>* prev_grid = &grid_1;
        vector<vector<int>>* cur_grid = &grid_2;

        grid_2[startRow+1][startColumn+1] = 1;

        for (int i = 0; i < maxMove; i++){

            swap(cur_grid, prev_grid);

            for (int row = 0; row < m+2; row++){
                for (int col = 0; col < n+2; col++){
                    if (row == 0 || col == 0 || row == m+1 || col == n+1)
                        (*cur_grid)[row][col] = (*prev_grid)[row][col];
                    else (*cur_grid)[row][col] = 0;
                }
            }

            for (int row = 1; row <= m; row++){
                for (int col = 1; col <= n; col++){
                    (*cur_grid)[row-1][col] += (*prev_grid)[row][col];
                    (*cur_grid)[row-1][col] %= MOD;

                    (*cur_grid)[row+1][col] += (*prev_grid)[row][col];
                    (*cur_grid)[row+1][col] %= MOD;

                    (*cur_grid)[row][col-1] += (*prev_grid)[row][col];
                    (*cur_grid)[row][col-1] %= MOD;

                    (*cur_grid)[row][col+1] += (*prev_grid)[row][col];
                    (*cur_grid)[row][col+1] %= MOD;
                }
            }

            // for (int row = 0; row < m+2; row++){
            //     for (int col = 0; col < n+2; col++){
            //         cout << (*prev_grid)[row][col] << " ";
            //     }
            //     cout << endl;
            // }
        }

        long long cnt = 0;
        for (int i = 1; i <= n; i++){
            cnt += (*cur_grid)[0][i];
            cnt = cnt % MOD;
            cnt += (*cur_grid)[m+1][i];
            cnt = cnt % MOD;
        }

        for (int i = 1; i <= m; i++){
            cnt += (*cur_grid)[i][0];
            cnt = cnt % MOD;
            cnt += (*cur_grid)[i][n+1];
            cnt = cnt % MOD;
        }

        return (int)cnt;
    }
};