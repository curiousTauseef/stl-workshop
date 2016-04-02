#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

template<typename Container>
void printContainer(const Container &c) {
    for(auto const &elem : c)
        std::cout << elem << " ";
    std::cout << std::endl;
}

bool customLessThan(const std::string &a, const std::string &b) {
    return a.back() < b.back();
}

void stupidSort() {
    int counter = 0;
    std::vector<int> vec(12);
    std::generate(vec.begin(), vec.end(), std::rand);
    while(!std::is_sorted(vec.begin(), vec.end())) {
        std::generate(vec.begin(), vec.end(), std::rand);
        counter++;
    }
    std::cout << counter << std::endl;
}

int main() {
    std::vector<std::string> vec = {"Daniel", "Bob", "Damn", "Carol", "Alice"};
    std::sort(vec.begin(), vec.end(), customLessThan);
    printContainer(vec);
}
