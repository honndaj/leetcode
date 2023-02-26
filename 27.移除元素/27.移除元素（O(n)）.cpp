// @before-stub-for-debug-begin
#include <vector>
#include <string>

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
        if (n == 0) return 0;
        if (n == 1) {
            if(nums[0] == val){
               nums[0] = 0;
               return 0;
            }
            return 1;
        }
        int p = 0, q = n - 1;
        int ans = 0;
         while(p != q) {
            while(nums[p] != val && p < q) p++;
            while(nums[q] == val && p < q) q--;
            int temp = nums[p];
            nums[p] = nums[q];
            nums[q] = temp;
         }
         q = n - 1;
         while(q >= 0){
            if(nums[q] != val){
                ans = q;
                break;
            }
            q--;
         }
         return q + 1;
    }
};
// @lc code=end

