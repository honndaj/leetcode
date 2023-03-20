/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(),sum = 0;
        for(int i = 0; i < n; i++) {
            sum+=nums[i];
        }
        if(n == 1|| sum%2) {
            return false;
        }
        vector<vector<bool>> f(n+1, vector<bool>(sum+1, 0));
        sum/=2;
        for(int i = 0; i<n;i++) {
            f[i][0] = 1;
        }
        f[0][nums[0]] = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= sum; j++) {
                f[i][j] = f[i-1][j];
                if(j-nums[i] >= 0) f[i][j] = (f[i][j] || f[i-1][j-nums[i]]);
            }
        }
        return f[n-1][sum];
    }
};
// @lc code=end

