#ifndef INC_8_22_WATCHDOG_H
#define INC_8_22_WATCHDOG_H
#pragma once
#include <functional>
#include <string>
#include <map>
#include <mutex>
#include <thread>
#include <chrono>
#include <atomic>

class Watchdog {
public:
    using Callback = std::function<void(const std::string &module)>;

    Watchdog(size_t timeoutMs, Callback cb)
        : _timeoutMs(timeoutMs), _callback(std::move(cb)), _running(true)
    {
        // 启动监控线程
        _monitor_thread = std::thread([this](){
            while(_running) {
                std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 检查周期100ms
                std::lock_guard<std::mutex> lk(_mtx);

                auto now = std::chrono::steady_clock::now();
                // 遍历所有模块，判断超时
                for(auto &item : _last_feed) {
                    auto &module_name = item.first;
                    auto &last_tp = item.second;
                    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_tp).count();
                    if ((size_t)diff > _timeoutMs) {
                        // 超时触发回调
                        if(_callback) {
                            _callback(module_name);
                        }
                        // 可选：触发后不再重复告警；注释掉则每次轮询都会告警
                        _last_feed.erase(module_name);
                    }
                }
            }
        });
    }

    ~Watchdog() {
        _running = false;
        if (_monitor_thread.joinable()) {
            _monitor_thread.join();
        }
    }

    // 喂狗：对应模块更新时间戳
    void feed(const std::string &module) {
        std::lock_guard<std::mutex> lk(_mtx);
        _last_feed[module] = std::chrono::steady_clock::now();
    }

private:
    size_t _timeoutMs;
    Callback _callback;

    std::mutex _mtx;
    std::map<std::string, std::chrono::steady_clock::time_point> _last_feed;
    std::atomic<bool> _running{false};
    std::thread _monitor_thread;
};

#endif //INC_8_22_WATCHDOG_H