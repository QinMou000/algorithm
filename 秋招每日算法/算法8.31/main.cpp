#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 210. 课程表 II
vector<int> findOrder(int numCourses, vector<vector<int> > &prerequisites) {
    unordered_map<int, vector<int> > edges; // 邻接表
    vector<int> in(numCourses); // 入度表

    for (auto e: prerequisites) {
        edges[e[1]].push_back(e[0]); // 建图
        in[e[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
        if (in[i] == 0)
            q.push(i); // 把全部入度为零的节点入队列
    vector<int> ans;
    while (q.size()) {
        int t = q.front();
        q.pop();
        ans.push_back(t);
        for (auto e: edges[t]) {
            // 删除当前节点连接节点的入度
            in[e]--;
            if (in[e] == 0)
                q.push(e); // 入度为零 加入队列
        }
    }
    for (auto e: in)
        if (e != 0) //  判断是否有环
            return {};
    return ans;
}

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    ListNode *Merge(ListNode *l1, ListNode *l2) {
        ListNode *l = l1;
        ListNode *r = l2;
        ListNode *dump = new ListNode(-1);
        ListNode *cur = dump;
        while (l && r) {
            if (l->val < r->val) {
                cur->next = l;
                l = l->next;
            } else {
                cur->next = r;
                r = r->next;
            }
            cur = cur->next;
        }
        if (l)
            cur->next = l;
        if (r)
            cur->next = r;
        return dump->next;
    }

    ListNode *MergeList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *r = MergeList(slow->next);
        slow->next = nullptr;
        ListNode *l = MergeList(head);
        return Merge(l, r);
    }

    ListNode *sortList(ListNode *head) { return MergeList(head); }
};

int search(vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    int div = nums[n - 1];
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (target == nums[mid])
            return mid;

        if (nums[l] <= nums[mid]) {
            // 左半区有序
            if (target >= nums[l] && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        } else {
            // 右半区有序
            if (target <= nums[r] && target > nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}

// 528. 按权重随机选择
class Solution2 {
    vector<int> arr;
    int totolTickets = 0;

    // 彩票调度：
    // 从前向后遍历进程列表，将每张票的值加到 counter 上，直到值超过 winner。
    // 这时，当前的列表元素所对应的进程就是中奖者。在我们的例子中，中奖彩票是 300。首先，
    // 计 A 的票后，counter 增加到 100。因为 100 小于 300，继续遍历。然后 counter 会增加到 150
    // （B 的彩票），仍然小于 300，继续遍历。最后，counter 增加到 400（显然大于 300），因此退
    // 出遍历，current 指向 C（中奖者）。
public:
    Solution2(vector<int> &w) : arr(w) {
        for (auto e: w) {
            totolTickets += e;
        }
    }

    int pickIndex() {
        int winner = rand() % totolTickets;
        int counter = 0;
        int i = 0;
        for (; i < arr.size(); i++) {
            counter += arr[i];
            if (counter > winner)
                break;
        }
        return i;
    }
};


int main() {
    string s;
    // random_device 从操作系统获取真随机数做种子
    std::random_device rd;
    std::mt19937 rng(rd()); // 传入随机种子
    std::uniform_int_distribution<int> int_dist(0, 99); // [0, 99] 闭区间
    for (int i = 0; i < 20; i++) {
        int seed = int_dist(rng);
        cout << seed << "\t";
        if (seed <= 75)
            s += "A";
        else s += "B";
    }
    cout << endl;
    for (auto c: s)
        cout << c << "\t";
    return 0;
}
