struct DNode {
    int key, val;
    DNode* next;
    DNode* prev;
    DNode(int key, int val)
        : key(key), val(val), next(nullptr), prev(nullptr) {}
};
class LRUCache {
private:
    unordered_map<int, DNode*> map; // key 和 DNode的映射
    DNode* head;                    // 双向循环链表的哨兵头节点
    DNode* tail;                    // 双向循环链表的哨兵尾节点
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
            DNode* NewNode = new DNode(key, value);
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
    void Remove(DNode* Node) { // 不是释放内存 只是从链表中删除
        DNode* Prev = Node->prev;
        DNode* Next = Node->next; // 保存前后节点

        Node->prev = nullptr;
        Node->next = nullptr; // 将当前节点剔除

        Prev->next = Next;
        Next->prev = Prev; // 将前后节点连起来
    }
    void HeadInsert(DNode* Node) {
        DNode* Next = head->next; // 保存哨兵头节点的下一个节点

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