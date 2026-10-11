//    237. 删除链表中的节点
// void deleteNode(ListNode* node) {
//     ListNode* cur = node;
//     ListNode* prev = nullptr;
//     while (cur->next) {
//         prev = cur;
//         cur->val = cur->next->val;
//         cur = cur->next;
//     }
//     prev->next = nullptr;
// }
void deleteNode(ListNode *node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

// 384. 打乱数组
class Solution {
    vector<int> nums;

  public:
    Solution(vector<int> &nums) : nums(nums) {}

    vector<int> reset() { return nums; }

    vector<int> shuffle() {
        // 洗牌算法，思路是在前n-1张牌洗好的情况下，第n张牌随机与前n-1张牌的其中一张牌交换，或者不换，即是随机洗牌
        vector<int> ans = nums;
        for (int i = 1; i < nums.size(); i++) {
            // 从 [0, i] 中随机选择一个位置
            int t = rand() % (i + 1);
            swap(ans[t], ans[i]);
        }
        return ans;
    }
};

// 1029. 两地调度
// 公司首先将这 2N 个人全都安排飞往 B 市
// 再选出 N 个人改变它们的行程 让他们飞往 A 市
// 如果选择改变一个人的行程 那么公司将会额外付出 price_A - price_B
// 这个费用可正可负
int twoCitySchedCost(vector<vector<int>> &costs) {
    int n = costs.size();

    sort(costs.begin(), costs.end(),
         [](const vector<int> &v1, const vector<int> &v2) { return v1[0] - v1[1] < v2[0] - v2[1]; });
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        ans += costs[i][0] + costs[i + n / 2][1];
    }
    return ans;
}