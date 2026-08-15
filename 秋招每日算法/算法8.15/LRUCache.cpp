#include <iostream>
#include <unordered_map>

struct Node {
    Node *_prev;
    Node *_next;
    int _val;
    int _key;

    Node() : _prev(nullptr), _next(nullptr), _val(0) {
    }

    Node(int key, int value)
        : _prev(nullptr), _next(nullptr), _key(key), _val(value) {
    }

    Node(Node *prev, Node *_next, int key, int value)
        : _prev(prev), _next(_next), _key(key), _val(value) {
    }
};

class LRUCache {
private:
    int _capacity;
    int _size;
    Node *_head;
    Node *_tail;
    std::unordered_map<int, Node *> _map;

public:
    LRUCache(const int capacity) : _capacity(capacity), _size(0) {
        _head = new Node();
        _tail = new Node();
        _head->_next = _tail;
        _tail->_prev = _head;
    }

    int get(int key) {
        if (_map.count(key)) {
            Node *NewHeadNode = _map[key];
            Erase(NewHeadNode);
            MoveToHead(NewHeadNode); // 默认它本来不在在List里面
            return NewHeadNode->_val;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (_map.count(key)) {
            Node *NewHeadNode = _map[key];
            NewHeadNode->_val = value;
            Erase(NewHeadNode);
            MoveToHead(NewHeadNode); // 默认它本来不在List里面
        } else {
            Node *NewNode = new Node(key, value);
            _map[key] = NewNode;
            MoveToHead(NewNode);
            _size++;
            if (_size > _capacity) {
                Node *TrueTailNode = _tail->_prev;
                _map.erase(TrueTailNode->_key);
                Erase(TrueTailNode);
            }
        }
    }

    void MoveToHead(Node *node) {
        Node *headNext = _head->_next;
        _head->_next = node;
        node->_next = headNext;

        headNext->_prev = node;
        node->_prev = _head;
    }

    void Erase(Node *node) {
        Node *Prev = node->_prev;
        Node *Next = node->_next;

        Prev->_next = Next;
        Next->_prev = Prev;
    }
};

int main() {
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    std::cout << lRUCache->get(1) << std::endl; // 返回 1
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    std::cout << lRUCache->get(2) << std::endl;; // 返回 -1 (未找到)
    lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    std::cout << lRUCache->get(1) << std::endl;; // 返回 -1 (未找到)
    std::cout << lRUCache->get(3) << std::endl;; // 返回 3
    std::cout << lRUCache->get(4) << std::endl;; // 返回 4
}
