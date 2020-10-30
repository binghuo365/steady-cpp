//
// Created by Administrator on 2020/10/29 0029.
//

#include <iostream>
#include "steady/NonCopyable.h"

class Test;
int main() {
    Test test();
#ifdef ABC

    std::cout << "hello world" <<std::endl;
#endif
    return 0;
}


