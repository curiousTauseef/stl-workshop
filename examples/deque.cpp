#include<iostream>
#include<deque>

template<typename T>
void printDeque(const std::deque<T> &deq) {
    for(auto &elem : deq)
        std::cout << elem << " ";
    std::cout << std::endl;
}

void * operator new(std::size_t n) throw(std::bad_alloc) {
    std::cout << "allocated: " << n << " bytes" << std::endl;
    void * p = malloc(n);
    return p;
}

int main () {
//initialise
    std::deque<int> deqInt = {0, 1, 2, 3, 4, 5};
//reference, iterator
    const int &second = deqInt.at(2);
    std::deque<int>::iterator it = deqInt.begin() +4;
//no guarantee when inserting elements in the middle
    deqInt.insert(deqInt.begin()+2, 42);
    printDeque(deqInt);
    std::cout << "reference: " << fourth << std::endl << "iterator: " << *it << std::endl;
    deqInt.insert(deqInt.begin()+4, 42);
    print Deque(deqInt);
    std::cout << "reference: " << fourth << std::endl << "iterator: " << *it << std::endl;
}
