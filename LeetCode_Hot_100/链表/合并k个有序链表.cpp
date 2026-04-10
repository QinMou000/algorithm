/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* Merge(ListNode* left, ListNode* right) {
        ListNode* tmp = new ListNode(-1);
        ListNode* cur = tmp;
        while (left && right) {
            if (left->val > right->val) {
                cur->next = right;
                right = right->next;
            } else {
                cur->next = left;
                left = left->next;
            }
            cur = cur->next;
        }
        cur->next = (left == nullptr) ? right : left;
        return tmp->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        while (lists.size() >= 2) {
            ListNode* newList = Merge(lists[0], lists[1]); // 归并头两个链表
            lists.erase(lists.begin(), lists.begin() + 2); // 将归并好的两个链表删除
            lists.push_back(newList);       // 将归并好的链表插入数组
        }
        return lists[0];
    }
};

// 第二遍写
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 定义优先级队列
        auto cmp = [](ListNode* n1, ListNode* n2) { return n1->val > n2->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        // 此处可以不用将所有节点全部插入
        // 可以先插入所有头结点
        // 之后再合并的时候在对后续节点做处理
        // 如果当前节点还有next节点
        // 就将next节点入队列
        // 可降低时间复杂度
        for (auto& arr : lists) {
            ListNode* cur = arr; // 头结点
            while (cur) {
                pq.push(cur);
                cur = cur->next;
            }
        }
        ListNode* dump = new ListNode(-1);
        ListNode* cur = dump;
        while (!pq.empty()) {
            ListNode* topNode = pq.top();
            pq.pop();
            cur->next = topNode;
            topNode->next = nullptr; // 清除next 避免冗余节点
            cur = cur->next;
        }
        return dump->next;
    }
};


// link : https://leetcode.cn/problems/merge-k-sorted-lists/description/?envType=study-plan-v2&envId=top-100-liked