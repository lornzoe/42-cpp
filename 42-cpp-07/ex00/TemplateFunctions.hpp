#ifndef TEMPLATEFUNCTIONS_HPP
#define TEMPLATEFUNCTIONS_HPP

#include <stdexcept>

template<typename T>
class MathOps
{
public:
    static T add(T a, T b) { return a + b; }
    static T subtract(T a, T b) { return a - b; }
    static T multiply(T a, T b) { return a * b; }
    static T divide(T a, T b) {
        if (b == 0) throw std::runtime_error("division by zero");
        return a / b;
    }
};

template<typename T>
T add(T a, T b) { return a + b; }

template<typename T>
T subtract(T a, T b) { return a - b; }

template<typename T>
T multiply(T a, T b) { return a * b; }

template<typename T>
T divide(T a, T b) {
    if (b == 0) throw std::runtime_error("division by zero");
    return a / b;
}

#endif // TEMPLATEFUNCTIONS_HPP
