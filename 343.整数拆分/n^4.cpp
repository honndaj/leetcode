/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int f[60][60][60];
    int integerBreak(int n) {
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                for(int k = 0; k <= n; k++) {
                    for(int l = 0; l <= k; l++) {
                        f[i][j][k] = -1;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            f[i][1][i] = i;
        }
        for(int i = 2; i <= n; i++) {
            for(int j = 2; j <= n; j++) {
                for(int k = 1; k < i; k++) {
                    for(int l = 1; l <= k; l++) {
                        f[i][j][k] = max(f[i][j][k], k*f[i-k][j-1][l]);
                    }
                }
            }
        }
        int ret = -1;
        for(int i = 2; i<= n; i++) {
            for(int j = 1; j < n; j++) {
                ret = max(ret, f[n][i][j]);
            }
        }
        return ret;
    }
};
// @lc code=end

