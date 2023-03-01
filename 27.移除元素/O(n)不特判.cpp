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
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int p = 0, q = n;
         while(p < q) {
            if(nums[p] != val){
                p++;
            }
            else {
                nums[p] = nums[q-1];
                q--;
            }
         }
         return p;
    }
};
// @lc code=end

