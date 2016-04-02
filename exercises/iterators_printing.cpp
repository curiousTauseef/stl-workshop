#include <iostream>
#include <iterator>
#include <vector>


template<typename Container>
void printSeqContainer(const Container &c, bool reversed = false) {
    if(reversed) {
        for(auto it = c.rbegin(); it != c.rend(); ++it)
            std::cout << *it << " ";
    }
    else {
        for(auto it = c.begin(); it != c.end(); ++it)
            std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    printSeqContainer(v, true);
}

