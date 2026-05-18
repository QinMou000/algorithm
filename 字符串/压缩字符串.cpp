class Solution {
public:
    int compress(vector<char>& chars) {
        int write_ptr = 0; // 读写指针
        int read_ptr = 0;
        while (read_ptr < chars.size()) {
            char cur_char = chars[read_ptr];
            int count = 0; // 重复字母计数
            while (read_ptr < chars.size() && cur_char == chars[read_ptr]) {
                // 统计当前字符重复出现的次数
                count++;
                read_ptr++;
            }
            chars[write_ptr++] = cur_char; // 先把当前字母写进去
            if (count > 1) {
                // 有重复才写入数字
                // 这里需要考虑count大于10的情况
                string cnt = to_string(count);
                for (int i = 0; i < cnt.size(); i++)
                    chars[write_ptr++] = cnt[i];
            }
        }
        return write_ptr;
    }
};

// link : https://leetcode.cn/problems/string-compression/description/