/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int,int>> q; 
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            while(!q.empty() && q.back().second <= nums[i]) {
                q.pop_back();
            }
            while(!q.empty() && q.front().first <= i-k) {
                q.pop_front();
            }
            q.push_back(pair<int,int>(i, nums[i]));
            if(i >= k-1) ans.push_back(q.front().second);
        }
        return ans;
    }
};
// @lc code=end

