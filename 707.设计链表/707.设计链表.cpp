/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int val):val(val), next(nullptr){}
    };

    MyLinkedList() {
        size = 0;
        head = new ListNode(-1);
    }
    
    int get(int index) {
        if(index + 1 > size) return -1;
        ListNode* p = head;
        while(p->next != nullptr && index > -1) {
            index--;
            p = p->next;
        }
        if(index == -1) return p->val;
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head->next;
        head->next = node;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* node = new ListNode(val), *p = head;
        while(p->next != nullptr) {
            p = p->next;
        }
        p->next = node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index == size) {
            addAtTail(val);
            return ;
        }
        ListNode* node = new ListNode(val), *p = head;
        while(p->next != nullptr && index > 0) {
            index--;
            p = p->next;
        }
        node->next = p->next;
        p->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index + 1 > size) return;
        ListNode* p = head;
        while(p->next != nullptr && index > 0) {
            index--;
            p = p->next;
        }
        p->next = p->next->next;
        size--;
    }

private:
    int size;
    ListNode* head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

