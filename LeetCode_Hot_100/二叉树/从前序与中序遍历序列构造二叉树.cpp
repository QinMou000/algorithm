// class Solution {
// private:
//     unordered_map<int, int> index;

// public:
//     TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
//         if (preorder_left > preorder_right) {
//             return nullptr;
//         }
        
//         // 前序遍历中的第一个节点就是根节点
//         int preorder_root = preorder_left;
//         // 在中序遍历中定位根节点
//         int inorder_root = index[preorder[preorder_root]];
        
//         // 先把根节点建立出来
//         TreeNode* root = new TreeNode(preorder[preorder_root]);
//         // 得到左子树中的节点数目
//         int size_left_subtree = inorder_root - inorder_left;
//         // 递归地构造左子树，并连接到根节点
//         // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
//         root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
//         // 递归地构造右子树，并连接到根节点
//         // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
//         root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
//         return root;
//     }

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int n = preorder.size();
//         // 构造哈希映射，帮助我们快速定位根节点
//         for (int i = 0; i < n; ++i) {
//             index[inorder[i]] = i;
//         }
//         return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
//     }
// };

// // 作者：力扣官方题解
// // 链接：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solutions/255811/cong-qian-xu-yu-zhong-xu-bian-li-xu-lie-gou-zao-9/
// // 来源：力扣（LeetCode）
// // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> map; // 先序 值和位置的映射
    /**
     * @param preorder 完整的前序遍历序列（常量引用，避免拷贝）
     * @param inorder 完整的中序遍历序列（常量引用，避免拷贝）
     * @param preorder_left 当前处理的前序遍历子区间的左边界索引（包含）
     * @param preorder_right 当前处理的前序遍历子区间的右边界索引（包含）
     * @param inorder_left 当前处理的中序遍历子区间的左边界索引（包含）
     * @param inorder_right 当前处理的中序遍历子区间的右边界索引（包含）
     *
     * @return TreeNode* 当前子区间对应的二叉树的根节点；若子区间无效（左边界 >
     * 右边界），返回 nullptr
     *
     * @note 1. 前序遍历子区间 [preorder_left, preorder_right] 与中序遍历子区间
     * [inorder_left, inorder_right] 包含的节点完全一致
     * @note 2. 递归终止条件：当 preorder_left > preorder_right
     * 时，说明当前子区间无节点，返回空指针
     * @note 3. 左右子树的区间划分依赖于中序遍历中根节点的位置，需配合类成员变量
     * index（中序值-索引映射）快速定位
     */
    TreeNode* buildTreeHelp(vector<int>& preorder, vector<int>& inorder,
                            int pre_left, int pre_right, int in_left,
                            int in_right) {
        if (pre_left > pre_right)
            return nullptr;                    // 判断结束条件
        int pre_root = pre_left;               // 拿到前序遍历根节点
        int in_root = map[preorder[pre_root]]; // 根据哈希表拿到中序遍历根节点

        TreeNode* root = new TreeNode(preorder[pre_root]); // 构造根节点

        int left_sub_size = in_root - in_left; // 左子树的节点总数

        root->left =
            buildTreeHelp(preorder, inorder, pre_left + 1,
                          pre_left + left_sub_size, in_left, in_root - 1);
        root->right =
            buildTreeHelp(preorder, inorder, pre_left + left_sub_size + 1,
                          pre_right, in_root + 1, in_right);

        return root; // 返回当前构造节点
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i; // 初始化哈希表
        return buildTreeHelp(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

// link : https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-100-liked