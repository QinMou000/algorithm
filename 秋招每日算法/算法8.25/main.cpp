#include <iostream>
#include <vector>

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
    // 2. 两数相加
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dump = new ListNode(-1);
        ListNode *node = dump;
        int car = 0;
        while (l1 || l2) {
            int cur = 0;
            if (l1) {
                cur += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                cur += l2->val;
                l2 = l2->next;
            }
            cur += car;
            car = cur / 10;
            cur %= 10;
            node->next = new ListNode(cur);
            node = node->next;
        }
        if (car)
            node->next = new ListNode(car);
        return dump->next;
    }

    // 19. 删除链表的倒数第 N 个结点
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dump = new ListNode(-1, head);
        ListNode *fast = dump;
        ListNode *prev = dump;
        ListNode *slow = dump;
        while (n--) {
            fast = fast->next;
        }
        while (fast) {
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
        prev->next = slow->next;

        return dump->next;
    }

    // 82. 删除排序链表中的重复元素 II
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dump = new ListNode(-1, head);
        ListNode *cur = dump;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                while (cur->next->next &&
                       cur->next->val == cur->next->next->val) {
                    cur->next = cur->next->next;
                }
                cur->next = cur->next->next;
            } else
                cur = cur->next;
        }
        return dump->next;
    }
};


int QucikSortHelper(std::vector<int> &nums, int l, int r) {
    int privot = nums[l];
    int left = l, right = r;
    while (left < right) {
        while (left < right && nums[right] >= privot)
            right--;
        while (left < right && nums[left] <= privot)
            left++;
        std::swap(nums[left], nums[right]);
    }
    std::swap(nums[l], nums[left]);
    return left; // 返回中点
}

void QucikSort(std::vector<int> &nums, int l, int r) {
    if (l >= r)
        return;

    int mid = QucikSortHelper(nums, l, r);

    QucikSort(nums, l, mid - 1);
    QucikSort(nums, mid + 1, r);
}

#include <stack>

void QuickSortNonR(std::vector<int> &nums, int l, int r) {
    std::stack<std::pair<int, int> > stk;
    stk.push(std::make_pair(l, r));
    while (!stk.empty()) {
        std::pair<int, int> Pair = stk.top();
        stk.pop();
        int mid = QucikSortHelper(nums, Pair.first, Pair.second);
        if (Pair.first < mid - 1)
            stk.push(std::make_pair(Pair.first, mid - 1));
        if (mid + 1 < Pair.second)
            stk.push(std::make_pair(mid + 1, Pair.second));
    }
}


void Print(const std::vector<int> nums) {
    for (auto e: nums)
        std::cout << e << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums1 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> nums2 = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    QucikSort(nums1, 0, nums1.size() - 1);
    QuickSortNonR(nums2, 0, nums2.size() - 1);
    Print(nums1);
    Print(nums2);

    return 0;
}
