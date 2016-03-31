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
int main() {
//copy
    std::vector<int> myVec = {1, 2, 3, 4, 5};
    printContainer(myVec);
    std::list<int> myLst(5);
    std::copy(myVec.begin(), myVec.begin()+3, myLst.begin());
    printContainer(myLst);
//swap
    std::vector<int> myVec2 = {1, 1, 1, 1};
    std::swap(myVec, myVec2);
    printContainer(myVec2);
//swap_ranges
    std::vector<int> vecA(5, 10);
    std::vector<int> vecB(5, 42);
    std::swap_ranges(vecA.begin()+1, vecA.end()-1, vecB.begin());
    printContainer(vecB);
//transform
    std::vector<int> vecC = {1, 2, 3, 4, 5, 4, 2, 4};
    std::list<int> myLst2;
    std::transform(vecC.begin(), vecC.end(), std::front_inserter(myLst2), [](int a){return a*2;});
    printContainer(myLst2);
//fill
    std::vector<int> emptyVec(10);
    std::fill(emptyVec.begin(), emptyVec.end(), 42);
    printContainer(emptyVec);
//remove - wtf
    printContainer(vecC);
    auto newEnd = std::remove(vecC.begin(), vecC.end(), 4);
    printContainer(vecC);
 //erase
    vecC.erase(newEnd, vecC.end());
    printContainer(vecC);
//rotate
    std::rotate(vecC.begin(), vecC.begin()+2, vecC.end());
    printContainer(vecC);

}

