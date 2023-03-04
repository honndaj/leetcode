/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    struct Status{
        int lsum, rsum, sum, maxn;
    };

    int maxSubArray(vector<int>& nums) {
        return divide(nums, 0, nums.size()-1).maxn;
    }
    
    Status divide(vector<int>& a, int l, int r) {
        if(l == r) {
            Status t;
            t.lsum = t.rsum = t.sum = t.maxn = a[l];
            return t;
        }
        Status s1, s2, s;
        int mid = (l+r)>>1;
        s1 = divide(a, l, mid);
        s2 = divide(a,mid+1, r);
        s.lsum = max(s1.lsum, s1.sum+s2.lsum);
        s.rsum = max(s2.rsum, s2.sum+s1.rsum);
        s.sum = s1.sum + s2.sum;
        s.maxn = max(max(s1.maxn, s2.maxn), s1.rsum + s2.lsum);
        return s;
    }
};
// @lc code=end

