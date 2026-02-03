class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int dislike = 0; // 不喜欢当前类型的三明治的人数
        while (!students.empty() && !sandwiches.empty()) {
            if (dislike == sandwiches.size())
                break;
            if (students[0] == sandwiches[0]) {
                pop_front(students);
                pop_front(sandwiches);
                dislike = 0; // 匹配成功disklike置零
            } else {
                int back = pop_front(students);
                students.push_back(back);
                dislike++; // 匹配失败说明有学生不喜欢这种类型的三明治
            }
        }
        return students.size();
    }
    int pop_front(vector<int>& vec) {
        if (vec.empty())
            return -1;
        int ret = vec[0];
        vec.erase(vec.begin());
        return ret;
    }
};

// link : https://leetcode.cn/problems/number-of-students-unable-to-eat-lunch/description/?envType=problem-list-v2&envId=queue&favoriteSlug=&difficulty=EASY