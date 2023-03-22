// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int ans = 0, sum = 0;
        for(int i = 0; i < stones.size(); i++) sum+=stones[i];
        while(ans <= 100) {
            if(check(ans, stones, sum)) break;
            ans++;
        }
        return ans;
    }
    bool check(int x, vector<int> a, int sum) {
        a.push_back(x);
        int n = a.size();
        sum+=x;
        if(sum%2) return 0;
        vector<bool> dp(sum+1, 0);
        sum/=2;
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = sum; j >= a[i]; j--) {
                dp[j] = dp[j] || dp[j-a[i]];
            }
        }
        return dp[sum];
    }
};
// @lc code=end

