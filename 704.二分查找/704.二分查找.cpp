/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (l+r)>>1;
            if(target <= nums[mid]){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return target == nums[l] ? l : -1;
    }
};
// @lc code=end

