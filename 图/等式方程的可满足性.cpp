class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // 把26个字母映射为26个整数
        // 把相等的字母都整为一个集合
        // 不相等的字母用并查集判断是否在一个集合
        // 在：相悖 false
        // 不在：相符 true

        vector<int> UnionFindSet(26, -1);

        auto FindRoot = [&UnionFindSet](int x) {
            while (UnionFindSet[x] >= 0) {
                x = UnionFindSet[x];
            }
            // 此时下标为x的位置就是根
            return x;
        };

        for (int i = 0; i < equations.size(); ++i) {
            if (equations[i][1] == '=') {
                // 相等 放进一个集合
                int first = equations[i][0] - 'a';
                int second = equations[i][3] - 'a';

                int root1 = FindRoot(first);
                int root2 = FindRoot(second);

                // 判断是否本来就在一个集合 FindRoot
                if (root1 != root2) {
                    // 把两个根的数据处理一下
                    // 把root2挂在root1上
                    UnionFindSet[root1] += UnionFindSet[root2];
                    // 设置第二个根的父节点
                    UnionFindSet[root2] = root1;
                }
            }
        }
        // 再次遍历一遍 不相等 就判断是否在一个集合
        for (int i = 0; i < equations.size(); ++i) {
            if (equations[i][1] == '!') {
                // 不相等 判断
                int first = equations[i][0] - 'a';
                int second = equations[i][3] - 'a';
                if (FindRoot(first) == FindRoot(second))
                    return false;
            }
        }
        return true;
    }
};

// link : https://leetcode.cn/problems/satisfiability-of-equality-equations/description/