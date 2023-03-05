/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), buy = -1, ans = 0;
        for(int i = 0; i < n; i++) {
            if(buy == -1) {
                buy = prices[i];
            }else {
                if(buy >= prices[i]) {
                    buy = prices[i];
                    continue;
                }
                if(i == n-1 || prices[i] >= prices[i+1]) {
                    ans += prices[i] - buy;
                    buy = -1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

