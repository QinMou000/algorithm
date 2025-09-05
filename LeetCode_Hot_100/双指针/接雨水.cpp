class Solution
{
public:
    int trap(vector<int> &h)
    {
        int n = h.size(), sum = 0, max = 0;
        for (auto e : h)
        {
            if (max < e)
                max = e; // 计算最大层数
            sum += e;    // 计算 h 的和
        }
        int left = 0, right = n - 1, layer = 1; // 层数
        int total_area = 0;                     // 将水也当成实心 计算总面积
        while (true)
        {
            if (layer > max)
                break; // 到最高的层数后 退出循环
            while (left <= right && h[left] < layer)
                left++; // 查找大于等于当前层数的左边界
            while (left <= right && h[right] < layer)
                right--; // 查找大于等于当前层数的右边界
            // cout << " layer " << layer << " left " << left << " right " <<
            // right
            //      << endl;
            total_area += right - left + 1; // 计算这一层的总面积
            // cout << total_area << endl;
            layer++;                 // 计算下一层的面积
            left = 0, right = n - 1; // 再次进入循环
        }
        // cout << total_area << " " << sum << endl;
        return total_area - sum; // 结果等于 总面积 减去实心面积
    }
};

// link : https://leetcode.cn/problems/trapping-rain-water/?envType=study-plan-v2&envId=top-100-liked