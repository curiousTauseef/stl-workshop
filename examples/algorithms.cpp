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
    std::vector<int> myVec = {1, 2, -3, 0, 4, 5, 8, 8, 1, 8};
    std::list<int> myLst = {2, -3};
    printContainer(myVec);
//all_of
    bool areAllPositive = std::all_of(myVec.egin(), myVec.end(), [](const int &elem){return elem > 0;});
    std::cout << std::boolalpha << "Are all positive? " << areAllPositive << std::endl;
//none_of
    bool areNonZero = std::none_of(myVec.begin(), myVec.end(), [](const int &elem){return elem == 0;});
    std::cout << std::boolalpha << "Are all nonzero? " << areNonZero << std::endl;
//find
    auto findEight = std::find(myVec.begin(), myVec.end(), 8);
    if(findEight!=myVec.end())
        std::cout << "Eight was found!" << std::endl;
//find_if
    auto firstNegative = std::find_if(myVec.begin(), myVec.end(), [](const int &elem){return elem < 0;});
    if(firstNegative!=myVec.end())
        std::cout << "Found negative element: " << *firstNegative << std::endl;
//find_end
    auto isLstPartOfVec = std::find_end(myVec.begin(), myVec.end(), myLst.begin(), myLst.end());
    if(isLstPartOfVec != myVec.end())
        std::cout << "The list is a part of the vector" << std::endl;
//for_each
    std::for_each(myVec.begin(), myVec.end(), [](int &elem){elem=elem/2;});
    printContainer(myVec);
}

