/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/
struct node {
    int key;
    int value;
    node* pre;
    node* next;
    node(int k, int v): key(k), value(v), pre(NULL), next(NULL) {};
};

class LRUCache {
    unordered_map<int, node*> mp;
    int capacity;  // 最大容量
    int size; // 当前容量
    node* head;
    node* tail;
  public:
    LRUCache(int c) {
        if (c < 0) {
            return;
        }
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->pre = head;
        mp.clear();
        capacity = c;
        size = 0;
    }

    int get(int k) {
        unordered_map<int, node*>::iterator it = mp.find(k);
        // if found
        if (it != mp.end()) {
            node* p = it->second;
            removeFromList(p);
            putToHead(p);
            return p->value;
        } else {
            return -1;
        }
    }

    void set(int k, int val) {
        if (capacity <= 0) {
            return;
        }
        unordered_map<int, node*>::iterator it = mp.find(k);
        if (it != mp.end()) {
            node* p = it->second;
            removeFromList(p);
            putToHead(p);
            p->value = val;
        } else {
            node* p = new node(k, val);
            putToHead(p);
            mp[k] = p;
            size++;
            if (size > capacity) {
                p = tail->pre;
                removeFromList(p);
                it = mp.find(p->key);
                mp.erase(it);
                delete p;
            }
        }
    }

    void removeFromList(node* p) {
        p->pre->next = p->next;
        p->next->pre = p->pre;
    }

    void putToHead(node* p) {
        p->next = head->next;
        p->pre = head;
        head->next->pre = p;
        head->next = p;
    }
};
