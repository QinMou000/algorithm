#include <iostream>
#include <condition_variable>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

condition_variable cond;

bool x = false;

int cnt = 10;

int main() {
    int i = 0;
    thread t1([&]() {
        while (i < cnt) {
            unique_lock<mutex> lock(mtx);

            cond.wait(lock, []() {
                // 满足这个条件才唤醒线程
                return x;
            });
            cout << "tid:" << this_thread::get_id() << " " << i++ << endl;
            x = !x;
            cond.notify_all();
        }
    });
    thread t2([&]() {
        while (i < cnt) {
            unique_lock<mutex> lock(mtx);

            cond.wait(lock, []() {
                // 满足这个条件才唤醒线程
                return !x;
            });
            cout << "tid:" << this_thread::get_id() << " " << i++ << endl;
            x = !x;
            cond.notify_all();
        }
    });

    t1.join();
    t2.join();
    return 0;
}
