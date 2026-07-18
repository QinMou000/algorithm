/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode *FindKthToTail(ListNode *pHead, int k) {
        if (!pHead)
            return nullptr;

        ListNode *cur = pHead;
        while (k && cur) {
            cur = cur->next;
            k--;
        }

        if (k > 0)
            return nullptr;

        ListNode *lastK = pHead;
        while (cur) {
            cur = cur->next;
            lastK = lastK->next;
        }
        return lastK;
    }
};

// link :
// https://www.nowcoder.com/practice/886370fe658f41b498d40fb34ae76ff9?tpId=265&rp=1&ru=%2Fexam%2Foj%2Fta&qru=%2Fexam%2Foj%2Fta&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D265&difficulty=&judgeStatus=&tags=&title=&gioEnter=menu