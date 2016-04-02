#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

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
    stupidSort();
}
