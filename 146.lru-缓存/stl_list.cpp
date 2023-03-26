// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
private:
    unordered_map<int, list<pair<int,int> >::iterator > cache;
    list<pair<int,int> > l;
    int cap;
    list<pair<int,int> >::iterator blank;
 
public:
    LRUCache(int capacity) : cap(capacity){
    }
    
    int get(int key) {
        list<pair<int,int> >::iterator node = cache[key];

        if(node == blank) {
            return -1;
        }
        pair<int,int> t = *node;
        l.erase(node);
        l.emplace_front(t.first, t.second);
        cache[key] = l.begin();
        return t.second;
    }
    
    void put(int key, int value) {
        list<pair<int,int> >::iterator node = cache[key];

        if(node == blank) {
            if(l.size() == cap) {
                auto p = l.end();p--;
                pair<int,int> t = *p;
                cache[t.first] = blank;
                l.pop_back();
            }
        }
        else {
            l.erase(node);
        }
        l.emplace_front(key, value);
        cache[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

