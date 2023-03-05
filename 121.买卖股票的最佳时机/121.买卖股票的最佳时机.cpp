/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), minn = prices[0], ans = 0;
        for(int i = 1; i < n; i++) {
            ans = max(ans, prices[i]-minn);
            minn = min(minn, prices[i]);
        }
        return ans;
    }
};
// @lc code=end

