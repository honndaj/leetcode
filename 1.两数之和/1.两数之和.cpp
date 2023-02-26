// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        bool flag = 1;

        for(size_t i = 0; i < nums.size() && flag; i++){
            for(size_t j = 0; j < nums.size() && flag; j++) {
                if (i == j) continue;
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    flag = 0;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

