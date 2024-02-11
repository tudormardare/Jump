#include <iostream>
#include <unordered_map>
#include <chrono>
#include <thread>
#include <functional>
#include <mutex>
#include "constants.h"

#define Timer TimerClass::getInstance()

class TimerClass {
public:

enum class eTimerMode {
    OnceUp,
    OnceDown,
    Cyclic,
    Infinite
};
    static TimerClass &getInstance() {
        static TimerClass instance;
        return instance;
    }

    // Impedisce la copia e l'assegnazione
    TimerClass(const TimerClass&) = delete;
    TimerClass& operator=(const TimerClass&) = delete;

    void addTimer(eTimer type, std::chrono::milliseconds duration, std::function<void()> callback, eTimerMode mode) {
        std::lock_guard<std::mutex
        > guard(mutex);
        timers[static_cast<int>(type)] = TimerInfo{duration, std::chrono::system_clock::now(), callback, mode, false, false};
    }

    void pauseTimer(eTimer type) {
        std::lock_guard<std::mutex
        > guard(mutex);
        if (timers.find(static_cast<int>(type)) != timers.end()) {
            timers[static_cast<int>(type)].paused = true;
        }
    }

    void restartTimer(eTimer type) {

        std::cout << "Restarting timer1" << std::endl;

        std::lock_guard<std::mutex> guard(mutex);
        std::cout << "Restarting timer2" << std::endl;
        if (timers.find(static_cast<int>(type)) != timers.end()) {
            std::cout << "Restarting timer3" << std::endl;
            auto& timer = timers[static_cast<int>(type)];
            timer.last = std::chrono::system_clock::now();
            timer.paused = false; // Riattiva il timer se era in pausa
            timer.expired = false; // Consente la ri-esecuzione per OnceUp e OnceDown
        }
    }

    bool isExpired(eTimer type) {
        std::lock_guard<std::mutex> guard(mutex);
        if (timers.find(static_cast<int>(type)) != timers.end()) {
            return timers[static_cast<int>(type)].expired;
        }
        return true; // Assumi che sia scaduto se non esiste
    }

    // Aggiungi questo metodo nella classe TimerClass
    long long getElapsedTime(eTimer type) {
        std::lock_guard<std::mutex> guard(mutex);
        if (timers.find(static_cast<int>(type)) != timers.end()) {
            auto& timer = timers[static_cast<int>(type)];
            auto now = std::chrono::system_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - timer.last).count();
            return elapsed;
        }
        return -1; // Restituisce -1 se il timer non esiste
    }


private:
    struct TimerInfo {
        std::chrono::milliseconds duration;
        std::chrono::time_point<std::chrono::system_clock> last;
        std::function<void()> callback;
        eTimerMode mode;
        bool expired;
        bool paused; // Aggiunto il flag di pausa
    };

    std::unordered_map<int, TimerInfo> timers;
    std::mutex
    mutex;
    std::thread timerThread;
    bool running;

    TimerClass() : running(true), timerThread(&TimerClass::run, this) {}

    ~TimerClass() {
        running = false;
        std::cout << "Distruttore timer" << std::endl;
        if (timerThread.joinable()) {
            timerThread.join();
        }
    }

    void run() {
        while (running) {
                auto now = std::chrono::system_clock::now();
            {
                std::lock_guard<std::mutex> guard(mutex);
                for (auto &it: timers) {
                    auto &timer = it.second;
                     if (!timer.expired && !timer.paused && now - timer.last >= timer.duration) {
                        if(timer.callback != nullptr) timer.callback();
                        if (timer.mode == eTimerMode::Cyclic) {
                            timer.last = now; // Resetta il timer per la modalità ciclica
                        }else {
                            timer.expired = true; // Imposta come scaduto per OnceUp e OnceDown
                        }
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
};
