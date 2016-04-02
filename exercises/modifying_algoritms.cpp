#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template<typename Container>
void printContainer(const Container &c) {
    for(auto const &elem : c)
        std::cout << elem << " ";
    std::cout << std::endl;
}

int transformFunction(const int &input) {
    if(input%2==0)
        return input/2;
    else
        return input*input;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> result;
    printContainer(vec);
    std::transform(vec.begin(), vec.end(), std::back_inserter(result), transformFunction);
    printContainer(result);
}
