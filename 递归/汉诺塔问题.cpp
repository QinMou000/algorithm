class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        move(n, A, B, C); // 借用B将A中的n个移动到C上面
    }
    void move(int n, vector<int>& A, vector<int>& B, vector<int>& C) {
        if (n == 1) {
            C.emplace_back(A.back());
            A.pop_back();
            return;
        }

        move(n - 1, A, C, B);     // 借用C将A中的n-1个移动到B上面
        C.emplace_back(A.back()); // 把A中的最后一个 移到 C 上面
        A.pop_back();             // A 没有了
        move(n - 1, B, A, C);     // 借用A将B上的n-1个移动到C上面
    }
};

// link : https://leetcode.cn/problems/hanota-lcci/description/?envType=problem-list-v2&envId=recursion