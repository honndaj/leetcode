// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int ans = INT_MAX, sum = 0,n = stones.size();
        for(int i = 0; i < stones.size(); i++) sum+=stones[i];
        vector<bool> dp(sum+1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = sum; j >= stones[i]; j--) {
                dp[j] = dp[j] || dp[j-stones[i]];
            }
        }
        for(int i = 0; i <= sum; i++) {
            if(dp[i]) {
                ans = min(ans, abs((sum-i)-i));
            }
        }
        return ans;
    }
};
// @lc code=end

