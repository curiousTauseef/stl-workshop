#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

template<typename Container>
void printContainer(const Container &c) {
    for(auto const &elem : c)
        std::cout << elem << " ";
    std::cout << std::endl;
}
int main() {
//are all less than five?
    std::vector<int> myVec = {1, 2, -3, 0, -4, 5, 8, 8, 1, 8};
    bool areAllLessThanFive = std::all_of(myVec.begin(), myVec.end(), [](const int &elem){return elem < 5;});
    std::cout << std::boolalpha << "Are all numbers less than five? " << areAllLessThanFive << std::endl;
//count negative
    int negative = std::count_if(myVec.begin(), myVec.end(), [](const int &elem){return elem < 0;});
    std::cout << "There are " << negative << " negative numbers in the vector" << std::endl;
}

