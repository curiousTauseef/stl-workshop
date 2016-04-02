#include <functional>
#include <iostream>

bool isMultiple(const int &a, const int &b) {
    return (a%b==0);
}

struct isMultipleFunctor {
    bool operator() (int a, int b) {return (a%b==0);}
};

int main() {
    using namespace std::placeholders;
    auto lambda = [](int a, int b){return (a%b==0);};
    isMultipleFunctor functor;
    auto bind = std::bind(std::equal_to<int>(), std::bind(std::modulus<int>(), _1, _2), 0);

    std::cout << std::boolalpha << isMultiple(14, 7) << std::endl;
    std::cout << std::boolalpha << functor(26, 13) << std::endl;
    std::cout << std::boolalpha << lambda(21, 3) << std::endl;
    std::cout << std::boolalpha << bind(24, 5) << std::endl;
}

