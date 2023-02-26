https://leetcode.cn/problems/squares-of-a-sorted-array/solution/you-xu-shu-zu-de-ping-fang-by-leetcode-solution/
以绝对值最小值为起点，分别往两边移动指针，谁小谁先进入vector，类似于快排，要处理一边剩下的。

具体地说，一开始我是先将最小值（下标记作pos）先存入vector，然后令p=pos-1，q=pos+1
但这样p会出现问题（当n为1的时候）。于是我改成了两个方向都从最小值开始，也就是p=pos,q=pos。但这样最后要erase一下第一个元素（因为存了两次）。但是官方解答二更为简单，p=pos，q=pos+1就可以避开这个问题了

官方题解方法三从两头开始往最小值走，逆序存vector，就无需处理一边剩下的。