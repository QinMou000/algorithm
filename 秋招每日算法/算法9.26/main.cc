// 933. 最近的请求次数

class RecentCounter {
    queue<int> q;

  public:
    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

// 2166. 设计位集
class Bitset {
    vector<uint8_t> nums;
    int cnt = 0;     // 1的个数
    int reserve = 0; // 翻转操作的次数 0:翻转偶数次 1 翻转奇数次
    // 异或：相同为 0，不同为 1
  public:
    Bitset(int size) { nums.resize(size); }

    void fix(int idx) {
        if (nums[idx] ^ reserve == 0) {
            nums[idx] ^= 1;
            cnt++;
        }
    }

    void unfix(int idx) {
        // 两者都为0 或者都为1
        if (nums[idx] ^ reserve == 1) {
            nums[idx] ^= 1;
            cnt--;
        }
    }

    void flip() {
        reserve ^= 1;
        cnt = nums.size() - cnt;
    }

    bool all() { return nums.size() == cnt; }

    bool one() { return cnt > 0; }

    int count() { return cnt; }

    string toString() {
        string str = "";
        for (auto &bit : nums)
            str += ((bit ^ reserve) + '0');
        return str;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */