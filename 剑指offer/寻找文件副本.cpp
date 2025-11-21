// class Solution {
// public:
//     int findRepeatDocument(vector<int>& documents) {
//         unordered_set<int> set;
//         for (auto& e : documents) {
//             if (set.count(e) == 0)
//                 set.insert(e);
//             else
//                 return e;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        int i = 0;                     // 初始化遍历指针，从数组第0个元素开始
        while (i < documents.size()) { // 遍历整个数组
            if (documents[i] == i) {   // 情况1：当前元素值与下标相等
                i++;      // 说明该位置已"归位"，无需处理，直接检查下一个元素
                continue; // 跳过后续操作，进入下一轮循环
            }
            // 情况2：当前元素值与下标不等，需要将其放到正确位置（下标=元素值）
            // 检查目标位置（documents[i]对应的下标）是否已有相同元素
            if (documents[documents[i]] == documents[i])
                return documents[i]; // 若目标位置已有相同元素，说明找到重复值，直接返回
            // 若目标位置没有相同元素，则交换当前元素与目标位置的元素
            swap(documents[i], documents[documents[i]]);
        }
        return -1;
    }
};

// link : https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/?envType=problem-list-v2&envId=XApvNy3p