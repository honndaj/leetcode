/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), sum = 0, ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(sum + nums[i] < 0) {
                sum = 0;
                ans = max(ans, nums[i]);
            }else {
                sum += nums[i];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
// @lc code=end

