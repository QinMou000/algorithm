#include <iostream>
#include <vector>
#include <functional>

std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
    int n = candidates.size();
    std::vector<std::vector<int> > ans;
    std::vector<int> output;
    std::function<void(int pos, int sum)> dfs = [&](int pos, int sum) {
        if (pos >= n) return;

        if (sum == target) {
            ans.emplace_back(output);
            return;
        }
        if (sum > target)
            return;
        // 不拿当前数
        dfs(pos + 1, sum);
        // 拿当前数
        output.push_back(candidates[pos]);
        dfs(pos, sum + candidates[pos]); // pos不变 可以多次选
        output.pop_back();
    };
    dfs(0, 0);
    return ans;
}


void PrintAns(const std::vector<std::vector<int> > ans) {
    for (auto vec: ans) {
        for (auto e: vec) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<int> candidates = {
        2, 3, 6, 7
    };
    int target = 7;

    std::vector<std::vector<int> > ans = combinationSum(candidates, target);

    PrintAns(ans);

    return 0;
}
