#include<iostream>
#include<vector>

template<typename T>
void printVector(const std::vector<T> &v) {
    std::cout << "size: " << v.size() << std::endl
              << "cap: " << v.capacity() << std::endl
              << "contents: ";
    for(size_t i=0; i<v.size(); i++)
        std::cout << v.at(i) << " ";
    std::cout << std::endl;
}

struct Car {
    int engine;
    Car(const int &eng) : engine(eng) {
        std::cout << "def c-tor" << std::endl;}
    Car(const Car &other) : engine(other.engine) {
        std::cout << "copy c-tor" << std::endl;}
    Car(Car &&other) noexcept : engine(std::move(other.engine)) {
        std::cout << "move c-tor" << std::endl;
    }
};


int main () {

    std::vector<Car> v;
    for(int i=0; i<10; i++) {
        v.push_back(Car(i));
        std::cout << std::endl;
    }
    return 0;
}
