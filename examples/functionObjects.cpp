#include <functional>
#include <iostream>

struct isEvenFunctor {
    bool operator() (int num) {return !(num%2);}
};

void exampleFunction(int n1, int n2, int n3, int n4, int n5) {
    std::cout << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << std::endl;
}

int main() {
//functor
    isEvenFunctor functor;
    std::cout << std::boolalpha << "isEven 7?: " << functor(7) << std::endl;
//mem_fn
    auto strLenFun = std::mem_fn(&std::string::length);
    std::string test = "HAL9000";
    std::cout << "str len: " << strLenFun(test);
//bind
    auto fibo = std::bind(exampleFunction, 1, 1, 2, 3, 5);
    fibo();
//wtf
    using namespace std::placeholders;
    auto fbind = std::bind(exampleFunction, _2, 8, _1, 6, 5);
    fbind(66, 22, 11);
}
