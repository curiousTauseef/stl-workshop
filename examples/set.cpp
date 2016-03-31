
#include <iostream>
#include <set>
#include <fstream>

template<typename Container>
void printContainer(const Container &c) {
    for(auto const &elem : c)
        std::cout << elem << " ";
    std::cout << std::endl;
}

int main() {
//initialise
    std::set<int, std::greater<int>> intSet = {84, 2, 13, 7, 9, 4, 4, 7, 84};
//insert
    intSet.insert(14);
    printContainer(intSet);
    std::pair<std::set<int>::iterator, bool> resultFailure = intSet.insert(14);
    std::pair<std::set<int>::iterator, bool> resultSuccess = intSet.insert(-2);
    std::cout << resultFailure.second << std::endl;
    std::cout << resultSuccess.second << std::endl;
//find
    std::set<int>::iterator isFound = intSet.find(-24);
    if(isFound != intSet.end())
        std::cout << "found" << std::endl;
//multiset
    std::multiset<int> mset = {55, 89, 1, 89, 2, 4, 6, 89, 6};
    printContainer(mset);
//count
    std::cout << mset.count(89) << std::endl;
//equal_range
    auto result = mset.equal_range(89);
    for(auto it = result.first; it!= result.second; it++)
        std::cout << *it << " ";
    std::cout << std::endl;
//upper and lower bound
    auto low = intSet.lower_bound(50);
    auto high = intSet.upper_bound(13);
    std::cout << *low << " " << *high << std::endl;
    printContainer(intSet);
}
