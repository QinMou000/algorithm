struct DNode {
    int key, val;
    DNode *next;
    DNode *prev;
    DNode(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};
class LRUCache {
  private:
    unordered_map<int, DNode *> map; // key 和 DNode的映射
    DNode *head;                     // 双向循环链表的哨兵头节点
    DNode *tail;                     // 双向循环链表的哨兵尾节点
    int capacity;
    int size;

  public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new DNode(-1, -1);
        tail = new DNode(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) { // 没找到
            return -1;
        }
        // 找到了
        // 拿出来 映射到双向链表
        auto Node = map.find(key)->second;
        // 找到对应的 Node 删除 并头插
        Remove(Node);
        HeadInsert(Node);
        return Node->val;
    }

    void put(int key, int value) {
        auto it = map.find(key);
        if (it == map.end()) { // map 里面没有
            // 头插进链表
            DNode *NewNode = new DNode(key, value);
            cout << "htf" << endl;
            cout << NewNode->key << " " << NewNode->val << endl;
            HeadInsert(NewNode);
            // 插入哈希
            map[key] = NewNode;
            size++;
            if (size > capacity) { // 大于 capacity
                // 删除哈希里面的kv
                map.erase(tail->prev->key);
                // 删除链表最后一个节点
                Remove(tail->prev);
                size--;
            }
        } else { // map 里面存了
            // 找到对应的 Node
            auto Node = map.find(key)->second;
            // 改 val 值
            Node->val = value;
            // 删除 并头插
            Remove(Node);
            HeadInsert(Node);
        }
    }
    void Remove(DNode *Node) { // 不是释放内存 只是从链表中删除
        DNode *Prev = Node->prev;
        DNode *Next = Node->next; // 保存前后节点

        Node->prev = nullptr;
        Node->next = nullptr; // 将当前节点剔除

        Prev->next = Next;
        Next->prev = Prev; // 将前后节点连起来
    }
    void HeadInsert(DNode *Node) {
        DNode *Next = head->next; // 保存哨兵头节点的下一个节点

        Node->next = Next;
        head->next = Node;

        Next->prev = Node;
        Node->prev = head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// 第二遍写
struct Node {
    int _k;
    int _v;
    Node *_prev;
    Node *_next;
    Node(int k, int v) : _k(k), _v(v), _prev(nullptr), _next(nullptr) {}
    Node() : _k(0), _v(0), _prev(nullptr), _next(nullptr) {}
};

class LRUCache {
  private:
    unordered_map<int, Node *> _map;
    Node *_head;
    Node *_tail;
    int _size;     // 当前有的节点数量
    int _capacity; // 题目要求的最大容量

  public:
    LRUCache(int capacity) : _capacity(capacity), _size(0), _head(new Node()), _tail(new Node()) {
        _head->_next = _tail;
        _tail->_prev = _head;
    }

    int get(int key) {
        if (_map.find(key) == _map.end())
            return -1;
        Node *node = _map[key];
        moveToHead(node);
        return node->_v;
    }

    void put(int key, int value) {
        if (_map.find(key) == _map.end()) {
            Node *newNode = new Node(key, value);
            _map[key] = newNode;
            addToHead(newNode);
            ++_size;
            if (_size > _capacity) {
                // 删除尾节点
                Node *removeNode = removeTail();
                _map.erase(removeNode->_k);
                delete removeNode;
                --_size;
            }
        } else {
            // 哈希表定位
            Node *node = _map[key];
            // 改值
            node->_v = value;
            // 移动
            moveToHead(node);
        }
    }
    void removeNode(Node *node) {
        node->_prev->_next = node->_next;
        node->_next->_prev = node->_prev;
    }
    void addToHead(Node *node) {
        node->_next = _head->_next;
        _head->_next = node;
        node->_next->_prev = node;
        node->_prev = _head;
    }
    void moveToHead(Node *node) {
        removeNode(node);
        addToHead(node);
    }
    Node *removeTail() {
        Node *tmp = _tail->_prev;
        removeNode(_tail->_prev);
        return tmp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// 第三遍写：
typedef struct Node {
    Node *prev_;
    Node *next_;
    int k_, v_;
    Node(int k, int v, Node *prev, Node *next) : prev_(prev), next_(next), k_(k), v_(v) {}
    Node() : prev_(nullptr), next_(nullptr), k_(0), v_(0) {}
} Node;

class LRUCache {
  private:
    Node *head_; // 哨兵头尾节点
    Node *tail_;
    unordered_map<int, Node *> map;
    int capacity_;
    int size_;

  public:
    LRUCache(int capacity) : capacity_(capacity), size_(0) {
        head_ = new Node();
        tail_ = new Node();
        head_->next_ = tail_;
        tail_->prev_ = head_;
    }

    int get(int key) {
        if (!map.count(key))
            return -1;
        Node *near = map[key]; // 定位到key 当作最近被使用的节点
        RemoveNode(near);      // 先把节点从链表里面删掉
        MoveToHead(near);
        return near->v_;
    }

    void put(int key, int value) {
        if (!map.count(key)) {
            // key 不存在
            Node *NewNode = new Node(key, value, nullptr, nullptr);
            MoveToHead(NewNode);
            map[key] = NewNode; // 在哈希中新增
            if (++size_ > capacity_) {
                // 容量满了 需要删除链表最后的节点
                int deleteNode = MoveTail();
                // 同时在哈希表中删除
                map.erase(deleteNode);
            }
        } else {
            // key 存在
            Node *near = map[key]; // 定位到key 当作最近被使用的节点
            near->v_ = value;      // 更新值
            RemoveNode(near);      // 先把节点从链表里面删掉
            MoveToHead(near);      // 移动节点到头部
        }
    }
    void MoveToHead(Node *node) {
        // 这里默认是node不在链表里面
        Node *TureHead = head_->next_; // 真正的链表头结点

        head_->next_ = node;
        node->next_ = TureHead;
        TureHead->prev_ = node;
        node->prev_ = head_;
    }
    void RemoveNode(Node *node) {
        Node *prev = node->prev_;
        Node *next = node->next_;

        prev->next_ = next;
        next->prev_ = prev;
    }
    int MoveTail() {
        Node *TailNode = tail_->prev_; // 真正的尾节点

        Node *prevTail = TailNode->prev_; // 尾节点的前一个节点

        prevTail->next_ = tail_;
        tail_->prev_ = prevTail;

        int TailNodeKey = TailNode->k_;
        delete TailNode;
        return TailNodeKey;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// link : https://leetcode.cn/problems/lru-cache-lcci/description/