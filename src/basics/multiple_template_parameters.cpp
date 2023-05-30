//
// Created by 阮波 on 2023/5/30.
//

#include <iostream>
using namespace std;


/*
 *  in this `max` function, we have two template parameters, T1 and T2.
 *  T1 and T2 can be different, so, what the type of the return value, T1, or T2.
 *
 *  Since C++14, we can use `auto` to let the compiler find out the return type.
 */
template<typename T1, typename T2>
static auto max(T1 a, T2 b) {
    return a > b ? a : b;
}

void multiple_template_parameters() {
    {
        auto r = max(1, 2);
        cout << "r:" << r << ", typeof r:" << typeid(r).name() << endl;  // 2, i

        auto r2 = max(1, 2.0);
        cout << "r2:" << r2 << ", typeof r2:" << typeid(r2).name() << endl;  // 2, d
    }
}
