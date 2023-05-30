//
// Created by 阮波 on 2023/5/30.
//
#include <iostream>
#include <complex>
#include <string>
using namespace std;


/*
 * requirement:
 *  1. type of `T` must have the `less then` (`<`) operator
 *  2. type of `T` must be copiable
 */
template<typename T>
static T my_max(T a, T b) {
    return b < a ? a : b;
}

/*
 *  For historical reasons, we can use hte keyword `class` instead of `typename` to define a
 *  type parameter.
 *
 *  Because use of `class` can be misleading (not only class types can be substituted for T),
 *  we should prefer the use of `typename` in the context.
 */
template<class T>
static T my_max_2(T a, T b) {
    return b < a ? a : b;
}

static void one_template_argument_type() {
    cout << "two same type parameter max" << endl;
    {
        int i = 10;
        cout << "max(7, 8):" << my_max(7, i) << endl;  // 10

        double f1 = 1.1;
        double f2 = -1.0;
        cout << "my_max(f1, f2):" << my_max(f1, f2) << endl;  // 1.1

        string s1 = "hello";
        string s2 = "hi";
        cout << "my_max(s1, s2):" << my_max(s1, s2) << endl;  // hi
    }
}

void invalid_function_template_calls() {
    std::complex<int> c1, c2;
//    auto c3 = my_max(c1, c2);  // error: std::complex<int> does not have the `<` operator

    std::atomic<int> a1 = 1;
    std::atomic<int> a2 = 2;
//    auto a3 = my_max(a1, a2);  // error: std::atomic<int> is not copiable

    {
//        auto r = my_max(1, 2.0);  // error:

        // we can specify the type by using my_max<double>
        auto r = my_max<double>(1, 2.0);
        cout << "r:" << r << ", type of r:" << typeid(r).name() << endl;  // 2, d

        // or cast the int `1` to `double`
        auto r2 = my_max(static_cast<double>(1), 2.0);
        cout << "r2:" << r << ", typeof r2:" << typeid(r2).name() << endl;  // 2, d
    }
}


/*
 * type deduction for default argument
 */
template<typename T>
static void func_default_argument(T = "") {
    cout << "template function with default argument:" << endl;
}

template<typename T = string>
static void func_default_argument_2(T = "") {
    cout << "template function with default argument and default template type" << endl;
}

static void call_template_function_with_default_argument() {
    func_default_argument(1);

//    func_default_argument();  // error:

    func_default_argument_2();  // OK
}


void function_templates() {
    one_template_argument_type();

    invalid_function_template_calls();

    call_template_function_with_default_argument();
}