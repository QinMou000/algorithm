class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        if (Bigheap.size() == Smallheap.size()) {
            // 两个堆大小相等 就要多一个元素在存放较大元素的小顶
            // 先插入大顶堆 之后再把大顶堆堆顶元素插入小顶堆
            // 这样可以确保 较大的一半和较小的一半分开
            Bigheap.push(num);
            Smallheap.push(Bigheap.top());
            Bigheap.pop();
        } else {
            // 两个堆不相等 那就是存放较大元素的小顶堆多了一个
            // 直接把元素插入 存放较小元素的大顶堆
            // 这里同上面的操作保证 较大的一半和较小的一半分开
            Smallheap.push(num);
            Bigheap.push(Smallheap.top());
            Smallheap.pop();
        }
    }

    double findMedian() {
        if (Bigheap.size() == Smallheap.size()) // 证明元素总数是偶数
            return ((double)Bigheap.top() + (double)Smallheap.top()) / 2;
        else
            return (double)Smallheap.top(); // 元素总数是奇数
    }

private:
    priority_queue<int, vector<int>, less<int>>
        Bigheap; // 大顶堆 存放较小的一半数
    priority_queue<int, vector<int>, greater<int>>
        Smallheap; // 小顶堆 存放较大的一半数
};

// 题解图片 : ![](https://pic.leetcode-cn.com/bcfaca2b1920d2dd6bbb01aeff990698eb36d53830c38ed499ea3239a15296b3-Picture1.png)

// link : https://leetcode.cn/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/description/?envType=problem-list-v2&envId=XApvNy3p

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */