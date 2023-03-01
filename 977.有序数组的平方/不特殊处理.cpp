// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int minn = 10010, pos = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) nums[i] = -nums[i];
            if(minn > nums[i]){
                minn = nums[i];
                pos = i;
            }
        }
        int p = pos, q = pos+1;
        vector<int> ans;
        while(p >= 0 && q < n) {
            if(nums[p] < nums[q]) {
                ans.push_back(nums[p]*nums[p]);
                p--;
            }
            else{
                ans.push_back(nums[q]*nums[q]);
                q++;
            }
        }
        while(p != -1){
            ans.push_back(nums[p]*nums[p]);
            p--;
        }
        while(q != n){
            ans.push_back(nums[q]*nums[q]);
            q++;
        }
        return ans;
    }
};
// @lc code=end

