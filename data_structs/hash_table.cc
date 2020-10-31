#include <cstring>

struct Item {
    int key, val;
    Item* next = nullptr;
    Item(int key_, int val_) : key{key_}, val{val_} {}
};

class MyHashMap {
    Item **map_;
    int size_ = 9973, max_depth = 1;
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        map_ = new Item*[size_];
        memset(map_, 0, size_*sizeof(Item*));
    }
    
    ~MyHashMap() {
        delete [] map_;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hash = key % size_;
        Item* item = map_[hash];
        if (!item) {
            map_[hash] = new Item(key, value);
        } else {
            while (item->next && item->key != key) item = item->next;
            
            if (item->key == key) item->val = value;
            else if (item->next) item->next->val = value;
            else {
                item->next = new Item(key, value);
                max_depth++;
            }
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hash = key % size_;
        Item* item = map_[hash];
        while (item && item->key != key) item = item->next;
        return item ? item->val : -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hash = key % size_;
        Item* item = map_[hash];
        if (!item) return;
        if (item->key == key) {
            map_[hash] = item->next;
            delete item;
        } else {
            while (item->next && item->next->key != key) item = item->next;
            if (!item->next) return;
            Item* tmp = item->next;
            item->next = tmp->next;
            tmp->next = nullptr;
            delete tmp;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */