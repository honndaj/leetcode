/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int f[60];
    int integerBreak(int n) {
        for(int i = 0; i <= n;i++) f[i]=-1;
        for(int i = 1; i< n; i++)f[i]=i;
        for(int i = 2; i<=n;i++) {
            for(int j = 1; j < i; j++) {
                f[i]= max(f[i], f[j]*(i-j));
            }
        }
        return f[n];
    }
};
// @lc code=end

