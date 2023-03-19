/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<vector<int>> f(m, vector<int>(n,0));
        f[0][0] = obstacleGrid[0][0] == 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j]) continue;
                if(i > 0) f[i][j]+=f[i-1][j];
                if(j > 0) f[i][j]+=f[i][j-1];
            }
        }
        return f[m-1][n-1];
    }
};
// @lc code=end

