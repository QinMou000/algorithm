/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
class Solution {
  public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode) {
        if (pNode->right) {
            // 右子树存在

            TreeLinkNode *cur = pNode->right;
            // 找右子树的最左节点
            while (cur->left) {
                cur = cur->left;
            }
            return cur;
        } else {
            // 右子树不存在
            TreeLinkNode *father = pNode->next;
            if (!father) // 没有父节点 没有右子树 中序遍历结束
                return nullptr;
            if (father->left == pNode) {
                // pNode为父节点的左子树 中序下一个就是父节点
                return father;
            } else if (father->right == pNode) {
                // pNode为父节点的右子树 需要不断往上找
                // 看祖宗节点有没有作为左子树的节点
                while (father->next) {
                    cout << father->val << endl;
                    if (father->next->left == father)
                        return father->next;
                    father = father->next;
                }
            }
        }
        return nullptr;
    }
};


// link : https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=23451&ru=%2Fpractice%2Fcf7e25aa97c04cc1a68c8f040e71fb84&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13