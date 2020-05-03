// Implementation of LRU cache using Hash Table and Doubly Linked List

#include <unordered_map>

struct Entry {
    int value;
    int key;
    Entry *left;
    Entry *right;

    Entry(int key_, int value_) : key{ key_ }, value{ value_ } { };
};

class LRUCache {
    std::unordered_map<int, Entry*> map_;
    // We use sentinel node in the list to make operations simpler
    Entry *start_ = new Entry(0, 0);
    int cap_;

    void remove(Entry *entry) {
        entry->left->right = entry->right;
        entry->right->left = entry->left;
    }

    void putAtTop(Entry *entry) {
        start_->right->left = entry;
        entry->right = start_->right;
        start_->right = entry;
        entry->left = start_;
    }
public:
    LRUCache(int capacity) : cap_{ capacity } {
        start_->left = start_->right = start_;
    }

    int get(int key) {
        auto entry = map_.find(key);
        if (entry != map_.end()) {
            remove(entry->second);
            putAtTop(entry->second);
            return entry->second->value;
        }
        return -1;
    }

    void put(int key, int value) {
        auto entry = map_.find(key);
        if (entry != map_.end()) {
            remove(entry->second);
            putAtTop(entry->second);
        } else {
            Entry *entry = new Entry(key, value);
            if (map_.size() > cap_) {
                Entry *old = start_->left;
                map_.erase(old->key);
                remove(old);
                delete old;
            }

            putAtTop(entry);
            map_[key] = entry;
        }
    }
};