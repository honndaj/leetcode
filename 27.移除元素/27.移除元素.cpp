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
         vector<int>::iterator it = nums.begin();
         while(it != nums.end()) {
            if(*it == val){
                it=nums.erase(it);
            }
            else it++;
         }
         return nums.size();
    }
};
// @lc code=end

