// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

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
        int n = nums.size(), l, r;
        bool flag = 0;
        vector<int> sum(n+1);
        sum[0] = 0;
        for(int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }

        l = 1;r = n + 1;
        while(l < r) {
            int mid = (l+r)>>1;
            if(flag = check(target, sum, mid)) {
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        if(l > n) l = 0;
        return l;
    }

    bool check(int target, vector<int> &sum, int len) {
        bool flag = 0;
        int n = sum.size();
        for(int i = 1; i + len <= n; i++) {
            if(sum[i + len -1] - sum[i-1] >= target) {
                flag = 1;
                break;
            }
        }
        return flag;
    }
};
// @lc code=end

