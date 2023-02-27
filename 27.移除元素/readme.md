https://leetcode.cn/problems/remove-element/solution/yi-chu-yuan-su-by-leetcode-solution-svxi/
官方题解的两个实现好好看一下，代码好简洁。

解法二中，left、right相等时不用特殊判断，自己赋给自己没有影响。

解法三和我的一样，但是不用它的写法特殊判断。（区间统一为左闭右开很重要）
left一旦等于val，就直接赋上right的值，注意这里不用管right是不是等于val，因为就算等于val，下一轮循环还是可以继续判断left（这个时候left指针不变）。