/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int f[20][20][20];
    int numTrees(int n) {
        for(int i = 0; i<20; i++){
            for(int j = 0; j<20;j++) {
                for(int k = 0; k<20; k++) {
                    f[i][j][k]=0;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            f[i][i][i] = 1;
        }
        int ret = 0;
        for(int i = 1; i<=n;i++) {
            ret+=dp(1,n,i);
        }
        return ret;
    }

    int dp(int l, int r, int x) {
        int ret = f[l][r][x];
        if(ret) return ret;
        for(int i = l; i <= x; i++) {
            for(int j = x; j<=r; j++) {
                if(l == x) ret += dp(x+1,r,j);
                else if(r == x) ret += dp(l, x-1, i);
                else ret += dp(l, x-1, i) * dp(x+1, r, j);
            }
        }
        return f[l][r][x] = ret;
    }
};
// @lc code=end

