class Solution {
public:
    bool verifyTreeOrder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size() - 1);
    }
    bool recur(vector<int>& postorder, int i, int j) {
        if (i >= j)
            return true; // 只有一个节点
        int root = postorder[j];
        int p = i; // 从i开始找第一个大于根节点的树
        while (postorder[p] < root)
            p++;
        // 左子树 [i, p - 1]
        // 右子树 [p, j - 1]
        // 左子树已经判断过了 只需判断右子树即可
        while (postorder[p] > root)
            p++;
        return p == j && recur(postorder, i, p - 1) &&
               recur(postorder, p, j - 1);
    }
};

// link : https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/description/?envType=problem-list-v2&envId=XApvNy3p