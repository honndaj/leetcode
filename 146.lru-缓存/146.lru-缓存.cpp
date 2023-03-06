/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
struct DLinkedNode {
    int key,value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode():key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value):key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int capacity, size;

public:
    LRUCache(int _capacity) : capacity(_capacity){
        size = 0;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        DLinkedNode* node = cache[key];
        if(node == nullptr) {
            return -1;
        }
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        DLinkedNode* node = cache[key];
        if(node == nullptr) {
            node = new DLinkedNode(key, value);
            if(size == capacity) {
                deleteTail();
            }
            addHead(node);
            cache[key] = node;
        }else{
            node->value = value;
            moveToHead(node);
        }
    }

    void addHead(DLinkedNode* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        size++;
    }
    void deleteTail() {
        DLinkedNode* t = tail->prev;
        tail->prev = t->prev;
        t->prev->next = tail;
        cache[t->key] = nullptr;
        delete t;
        size--;
    }
    void moveToHead(DLinkedNode* node) {
        DLinkedNode* p = node->prev;
        DLinkedNode* q = node->next;
        p->next = q;
        q->prev = p;
        size--;
        addHead(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

