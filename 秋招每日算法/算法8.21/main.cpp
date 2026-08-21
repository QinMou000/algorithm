#include <iostream>
#include <memory.h>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {
    }
};


class Solution {
public:
    // 110. 平衡二叉树
    bool isBalanced(TreeNode *root) {
        if (!root)
            return true;
        if (abs(MaxDepth(root->left) - MaxDepth(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    // 找单边最大深度
    int MaxDepth(TreeNode *root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int l = MaxDepth(root->left) + 1;
        int r = MaxDepth(root->right) + 1;
        return std::max(l, r);
    }

    // 100. 相同的树
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q)return true;
        if (!p || !q)return false;
        if (p->val != q->val)return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    // 543. 二叉树的直径
    int ans = 0;

    int diameterOfBinaryTree(TreeNode *root) {
        dfs(root);
        return ans;
    }

    // 找该节点左右子树的最大深度
    int dfs(TreeNode *root) {
        if (!root)return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        ans = std::max(l + r, ans);
        return std::max(l, r) + 1;
    }
};

// 208. 实现 Trie (前缀树)
class Trie {
    Trie *next[26];
    bool IsEnd;

public:
    Trie() {
        memset(next, 0, sizeof(next));
        IsEnd = false;
    }

    void insert(std::string word) {
        Trie *cur = this;
        for (auto c: word) {
            if (cur->next[c - 'a'] == NULL)
                cur->next[c - 'a'] = new Trie();
            cur = cur->next[c - 'a'];
        }
        cur->IsEnd = true;
    }

    bool search(std::string word) {
        Trie *cur = this;
        for (auto c: word) {
            cur = cur->next[c - 'a'];
            if (cur == NULL)
                return false;
        }
        return cur->IsEnd;
    }

    bool startsWith(std::string prefix) {
        Trie *cur = this;
        for (auto c: prefix) {
            cur = cur->next[c - 'a'];
            if (cur == NULL)
                return false;
        }
        return true;
    }

    // 题解 : https://leetcode.cn/problems/implement-trie-prefix-tree/solutions/98390/trie-tree-de-shi-xian-gua-he-chu-xue-zhe-by-huwt
};


#include <iostream>
#include <vector>
#include <future>
#include <mutex>
#include <atomic>
#include <thread>
#include <chrono>

// 任务编排器
struct TaskOrchestrator {
    std::atomic<int> completed{0};
    const int total_pre{5};
    std::vector<int> results;
    std::mutex mtx;
    std::atomic<bool> task6_invoked{false};

    // 任务1~5，模拟耗时业务
    int task1() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1200));
        std::cout << "task1 done\n";
        return 101;
    }

    int task2() {
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        std::cout << "task2 done\n";
        return 102;
    }

    int task3() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        std::cout << "task3 done\n";
        return 103;
    }

    int task4() {
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        std::cout << "task4 done\n";
        return 104;
    }

    int task5() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "task5 done\n";
        return 105;
    }

    // 汇总任务6，依赖前5全部结果
    void task6(std::vector<int> res) {
        std::cout << "\n==== run task6 ====\n";
        int sum = 0;
        for (auto v: res) {
            sum += v;
            std::cout << v << " ";
        }
        std::cout << "\nsum = " << sum << "\ntask6 finished\n";
    }

    // 每个子任务完成回调，运行在子线程
    void onTaskDone(int val) {
        std::lock_guard<std::mutex> lock(mtx);
        results.push_back(val);
        completed++;

        // 全部5个完成，且task6还没执行，则执行任务6
        if (completed == total_pre && !task6_invoked) {
            task6_invoked = true;
            // 直接在当前回调线程执行任务6，主线程完全不阻塞
            task6(results);
        }
    }

    std::vector<std::future<int> > futures; // 保存future，避免临时析构阻塞

    void start() {
        auto wrap = [this](auto func) {
            return [=]() {
                int ret = func();
                this->onTaskDone(ret);
                return ret;
            };
        };

        futures.emplace_back(std::async(std::launch::async, wrap([this] { return task1(); })));
        futures.emplace_back(std::async(std::launch::async, wrap([this] { return task2(); })));
        futures.emplace_back(std::async(std::launch::async, wrap([this] { return task3(); })));
        futures.emplace_back(std::async(std::launch::async, wrap([this] { return task4(); })));
        futures.emplace_back(std::async(std::launch::async, wrap([this] { return task5(); })));
    }
};

int main() {
    TaskOrchestrator orch;
    orch.start();

    // ========== 主线程不会阻塞，继续做自己的业务 ==========
    for (int i = 0; i < 8; ++i) {
        std::cout << "[MAIN thread working] loop " << i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    std::cout << "Main thread work finished.\n";
    // 注意：main不要立刻return，否则进程直接退出，子线程还没跑完；
    // 实际项目中主线程会跑事件循环，这里模拟等待，不是业务等待任务结果，只是防止进程退出
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 0;
}
