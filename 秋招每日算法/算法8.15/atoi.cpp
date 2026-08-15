#include <iostream>
#include <string>

// 实现 atoi：string 转 int
int AtoI(const std::string &s) {
    int i = 0;
    const size_t n = s.size();
    int flag = 1;

    while (i < n) {
        // 跳空格
        if (s[i] == ' ')
            i++;
        else break;
    }
    // 只判断一次符号
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-')
            flag = -1;
        i++;
    }

    long long ret = 0;
    while (i < n) {
        if (s[i] < '0' || s[i] > '9') {
            break;
        }
        ret = ret * 10 + s[i] - '0';
        if (flag == 1 && ret > INT_MAX) return INT_MAX;
        if (flag == -1 && ret > (long long) INT_MAX + 1) return INT_MIN;
        i++;
    }
    return ret * flag;
}

int main() {
    const std::string s1 = "-42";
    const std::string s2 = "4193 with words";
    const std::string s3 = "words and 987";
    const std::string s4 = "00000-42a1234";
    const std::string s5 = "-042";
    const std::string s6 = "123abc456";
    const std::string s7 = "2147483647";
    const std::string s8 = "2147483648";
    const std::string s9 = "-2147483649";
    const std::string s10 = "";
    const std::string s11 = "    ";

    std::cout << s1 << " -> " << AtoI(s1) << " -> -42" << std::endl;
    std::cout << s2 << " -> " << AtoI(s2) << " -> 4193" << std::endl;
    std::cout << s3 << " -> " << AtoI(s3) << " -> 0" << std::endl;
    std::cout << s4 << " -> " << AtoI(s4) << " -> 0" << std::endl;
    std::cout << s5 << " -> " << AtoI(s5) << " -> -42" << std::endl;
    std::cout << s6 << " -> " << AtoI(s6) << " -> 123" << std::endl;
    std::cout << s7 << " -> " << AtoI(s7) << " -> 2147483647" << std::endl;
    std::cout << s8 << " -> " << AtoI(s8) << " -> 2147483647" << std::endl;
    std::cout << s9 << " -> " << AtoI(s9) << " -> -2147483648" << std::endl;
    std::cout << s10 << " -> " << AtoI(s10) << " -> 0" << std::endl;
    std::cout << s11 << " -> " << AtoI(s11) << " -> 0" << std::endl;

    return 0;
}
