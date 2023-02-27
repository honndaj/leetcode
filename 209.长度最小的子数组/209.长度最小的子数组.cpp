/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), p = 0, q = 1, sum = 0, len = 0 ,ret = 100010;
        while(q <= n) {
            while(sum < target && q <= n){
                sum += nums[q - 1];
                q++;
                len++;
            }
            while(sum >= target) {
                ret = min(ret, len);
                sum -= nums[p++];
                len--;
            }
        }

        return ret == 100010 ? 0 : ret;
    }
};
// @lc code=end

