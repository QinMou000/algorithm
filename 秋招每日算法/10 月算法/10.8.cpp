// 540. 有序数组中的单一元素
int singleNonDuplicate(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        // 假设 x 为答案
        // 那么左边的成对元素的较小下标都为偶数，较大下标为奇数
        // 那么右边的成对元素的较小下标都为奇数，较大下标为偶数
        // 根据 mid 坐标的奇偶性来决定
        // 是和 mid + 1 判断相等还是 mid - 1
        // mid 为奇数：mid + 1 = mid ^ 1
        // mid 为偶数：mid - 1 = mid ^ 1
        if (nums[mid] == nums[mid ^ 1]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return nums[l];
}

// 210. 课程表 II
vector<int> findOrder(int numCourses, vector<vector<int>> &pre) {
    unordered_map<int, vector<int>> Edge; // 邻接表
    vector<int> in(numCourses);           // 入度表

    // 建表
    for (auto e : pre) {
        Edge[e[1]].push_back(e[0]);
        in[e[0]]++;
    }
    queue<int> q; // 存 入度为零的节点
    // 刚开始 压入所有入度为零的节点
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (q.size()) {
        // 访问队列中入度为零的节点
        int t = q.front();
        q.pop();
        ans.push_back(t);
        for (auto out : Edge[t]) {
            // 当前这个入度为零的节点还有一些出度
            if (--in[out] == 0)
                q.push(out);
        }
    }
    // 判断是否有环
    for (auto e : in) {
        if (e != 0)
            return {};
    }
    return ans;
}