/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int f[60][60];
    int integerBreak(int n) {
        for(int i = 2; i <= n;i++) {
            for(int j = 1; j < i; j++) {
                for(int k = 1; k <= j; k++) {
                    f[i][j] = -1;
                }
            }
        }
        for(int i = 1; i <= n; i++) f[i][i] = i;
        for(int i = 2; i <= n;i++) {
            for(int j = 1; j < i; j++) {
                for(int k = 1; k <= j; k++) {
                    f[i][j] = max(f[i][j], j*f[i-j][k]);
                }
            }
        }
        int ret = -1;
        for(int i = 1; i<n; i++) ret = max(ret, f[n][i]);
        return ret;
    }
};
// @lc code=end

