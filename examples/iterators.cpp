#include <iostream>
#include <vector>
#include <list>

template<typename Container>
void printContainer(const Container &c) {
    for(auto it = c.begin(); it!= c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template<typename RandomAccessIter>
void algorithm(RandomAccessIter begin, RandomAccessIter end, std::random_access_iterator_tag) {
    std::cout << "algorithm for random access iterators" << ", (" << *begin << ", " << *(--end) << ")" << std::endl;
}

template<typename BidirectionalIter>
void algorithm(BidirectionalIter begin, BidirectionalIter end, std::bidirectional_iterator_tag) {
    std::cout << "algorithm for bidirectional iterators" << ", (" << *begin << ", " << *(--end) << ")" << std::endl;
}

template<typename Iter>
void algorithm(Iter begin, Iter end) {
    algorithm(begin, end, typename std::iterator_traits<Iter>::iterator_category());
}

int main() {
//vector
    std::vector<int> v = {11, 22, 33, 44, 55, 66};
    printContainer(v);
    auto vit1 = v.begin();
    auto vit2 = v.begin()+3;
    std::cout << "dist: " << std::distance(vit1, vit2) << std::endl;
    algorithm(v.begin(), v.end());
//list
    std::list<int> lst = {1, 2, 3, 4, 5, 6, 7};
    printContainer(lst);
    auto lit1 = lst.begin();
    auto lit2 = std::next(lst.begin(), 4);
    std::advance(lit1, 1);
    std::cout << "dist: " << std::distance(lit1, lit2) << std::endl;
    algorithm(lst.begin(), lst.end());
}

