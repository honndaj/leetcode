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
        int n = nums.size(), ans = 0, flag = 0, i = 0;
        while(i + 1 < n && nums[i] == nums[i+1]) i++;
        if(i+1 == n) return 1;
        flag = nums[i] < nums[i+1] ? 1 : 0;
        i++;
        ans = 2;
        while(i+1 < n) {
            if(flag) {
                if(nums[i] > nums[i+1]){
                    flag = 0;
                    ans++;
                }
            }
            else {
                if(nums[i] < nums[i+1]) {
                    flag = 1;
                    ans++;
                }
            }
            i++;
        }
        return ans;
    }
};
// @lc code=end

