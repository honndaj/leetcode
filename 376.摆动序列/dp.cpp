/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int up = 1, down = 1, n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i-1] < nums[i]) {
                up = max(up, down+1);
            }
            else if (nums[i-1] > nums[i]) {
                down = max(up+1, down);
            }
        }
        return max(down, up);
    }
};
// @lc code=end

