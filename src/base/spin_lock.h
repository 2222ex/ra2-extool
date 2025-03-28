﻿#ifndef SPIN_LOCK_H
#define SPIN_LOCK_H

#include <atomic>

class SpinLock
{
private:
    std::atomic_flag flag = ATOMIC_FLAG_INIT;

public:
    void lock()
    {
        while (flag.test_and_set(std::memory_order_acquire))
            ;
    }

    void unlock()
    {
        flag.clear(std::memory_order_release);
    }
};

#endif // SPIN_LOCK_H
