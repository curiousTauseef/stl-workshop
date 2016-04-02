#include <iostream>
#include <set>
#include <fstream>
#include <vector>

template<typename Container>
void printContainer(const Container &c) {
    for(auto const &elem : c)
        std::cout << elem << " ";
    std::cout << std::endl;
}

std::vector<std::string> readFileIntoVector(const std::string &filename)
{
    std::vector<std::string> fileContents;
    std::ifstream file;
    file.open(filename);
    if(!file.is_open()) exit(0);

    std::string word;
    while(file >> word)
    {
        fileContents.push_back(word);
    }
    return fileContents;
}

int main() {
    std::vector<std::string> hamletVector = readFileIntoVector("C:/cygwin64/home/dziadzio/stl/hamlet.txt");
    std::set<std::string> hamletSet (hamletVector.begin(), hamletVector.end());
    std::multiset<std::string> hamletMultiSet (hamletVector.begin(), hamletVector.end());

    std::cout << "total count: " << hamletSet.size() << std::endl;
    std::cout << "count('the'): " << hamletMultiSet.count("the") << std::endl;
}
