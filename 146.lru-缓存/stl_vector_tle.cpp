/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
private:
    vector<pair<int,int> > cache;
    int cap;

public:
    LRUCache(int capacity) : cap(capacity) {

    }
    
    int get(int key) {
        for(int i = 0; i < cache.size(); i++){
            auto c = cache[i];
            if(c.first == key) {
                cache.erase(cache.begin()+i);
                cache.push_back(c);
                return c.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        int index = -1;
        for(int i = 0; i < cache.size(); i++) {
            if(cache[i].first == key) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            if(cache.size() == cap) {
                cache.erase(cache.begin());
            }
        }
        else {
            cache.erase(cache.begin()+index);
        }
        cache.emplace_back(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

