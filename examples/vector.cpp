#include<iostream>
#include<vector>

template<typename T>
void printVector(const std::vector<T> &v) {
    std::cout << "size: " << v.size() << std::endl
              << "cap: " << v.capacity() << std::endl
              << "contents: ";
    for(size_t i=0; i<v.size(); i++)
        std::cout << v.at(i) << " ";
    std::cout << std::endl;
}

void oldStyleApi(int * table, int size) {
    std::cout << "old style api: " << std::endl;
    for(int i=0; i<size; i++)
        std::cout << table[i] << " ";
}

int intAverage(const std::vector<int> &data) {
    int sum = 0;
    for(size_t i=0; i<data.size(); i++)
        sum += data.at(i);
    return sum/data.size();
}

template<typename T>
T average(const std::vector<T> &data) {
    T sum = 0;
    T count = 1;
    for(size_t i=0; i<data.size(); i++)
        sum += data.at(i);
        count += 1;
    return sum/count;
}

std::ostream& operator<< (std::ostream &s, const std::vector<int> data) {
    for (size_t i=0; i<data.size(); i++)
        s << data.at(i) << " ";
    return s;
}


int main () {

    std::vector<int> v = {3, 5};
    std::vector<double> v2 = {3, 4};
    printVector(v);
    std::cout << v << std::endl;
    std::cout << "integer average: " << intAverage(v) << std::endl;
    std::cout << "average: " << average(v2) << std::endl;

    return 0;
}
