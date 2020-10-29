//
// Created by Administrator on 2020/10/29 0029.
//

#ifndef STEADY_NONCOPYABLE_H
#define STEADY_NONCOPYABLE_H

namespace steady {
    class NonCopyable {
    protected:
        NonCopyable(){}
        ~NonCopyable(){}
        NonCopyable(const NonCopyable&) = delete;
        NonCopyable &operator=(const NonCopyable&) = delete;
        NonCopyable(NonCopyable&&) noexcept = default;
        NonCopyable &operator=(NonCopyable&&) noexcept = default;
    };
}


#endif //STEADY_NONCOPYABLE_H
