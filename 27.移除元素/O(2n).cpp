// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem27.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), p, q;
        for(p = 0, q = 0; q < n; q++) {
            if(nums[q] != val) {
                swap(nums[p], nums[q]);
                p++;
            }
        }
        return p;
    }
};
// @lc code=end

