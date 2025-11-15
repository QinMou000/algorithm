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

// 第二次写:
class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int sum = 0, max_layer = 0;
        for (auto e : h) {
            sum += e;                                    // 计算整个黑色块的和
            max_layer = (e > max_layer) ? e : max_layer; // 计算最大层数
        }
        int left = 0, right = n - 1, layer = 1; // 当前所处层数

        int summary = 0;
        while (left <= right && layer <= max_layer) {
            while (h[left] < layer)
                left++;
            while (h[right] < layer)
                right--;
            summary += (right - left + 1); // 加上当前层数黑色块和水的总量
            layer++;
            // cout << summary << " " << layer << endl;
        }
        // cout << summary << " " << layer << " " << sum << " " << max_layer
        //      << endl;
        return summary - sum; // 用总和减去只有黑色块的数量
    }
};