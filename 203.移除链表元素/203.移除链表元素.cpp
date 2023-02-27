// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = head;
        ListNode* pre = nullptr;
        while(p != nullptr) {
            if(p->val == val) {
                if(pre != nullptr) {
                    pre->next = p->next;
                }
                else {
                    head = p->next;
                }
            }
            else {
                pre = p;
            }
            p = p->next;
        }
        return head;
    }
};
// @lc code=end

