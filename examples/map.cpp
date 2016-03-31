#include  <iostream>
#include <map>

template<typename Container>
void printContainer(const Container &c) {
    for(auto const &elem : c)
        std::cout << elem << " ";
    std::cout << std::endl;
}

template <typename T1, typename T2>
std::ostream &operator << (std::ostream &s, const std::pair<T1, T2> &p) {
    s << "(" << p.first << ", " << p.second << ")";
    return s;
}

int main() {
//initialise
    std::map<int, std::string> mapNames;
//add elements
    mapNames[3] = "Ala";
    mapNames.insert(std::pair<int, std::string>(4, "Alice"));
    mapNames.insert(std::make_pair(6, "Bob"));
    printContainer(mapNames);
//accessing values by key - returns default when the key doesn't exist
    std::cout << mapNames[3] << std::endl;
    std::cout << mapNames[2] << std::endl;
//multimap
    std::multimap<int, std::string> multiMapNames;
    multiMapNames.insert(std::make_pair(6, "Alice"));
    multiMapNames.insert(std::make_pair(6, "Bob"));
    multiMapNames.insert(std::make_pair(6, "Carol"));
    multiMapNames.insert(std::make_pair(1, "Damn, Daniel"));
    printContainer(multiMapNames);
}
