#include  <iostream>
#include <map>
#include <fstream>

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

std::map<std::string, int> computeWordHistogram(const std::string &filename)
{
    std::map<std::string, int> histogram;
    std::ifstream file;
    file.open(filename);
    if(!file.is_open()) exit(0);

    std::string word;
    while(file >> word)
    {
        histogram[word]++;
    }
    return histogram;
}

std::map<int, int> computeWordLengthHistogram(const std::string &filename)
{
    std::map<int, int> histogram;
    std::ifstream file;
    file.open(filename);
    if(!file.is_open()) exit(0);

    std::string word;
    while(file >> word)
    {
        histogram[word.length()]++;
    }
    return histogram;
}

int countWordsStartingWithLetter(char letter, std::map<std::string, int> text) {
    int counter = 0;
    for(auto const &elem : text)
        if(elem.first[0] == letter)
            counter ++;
    return counter;
}

int main() {
    std::map<std::string, int> histogram = computeWordHistogram("C:/cygwin64/home/dziadzio/stl/hamlet.txt");
    std::map<int, int> wordLengthHistogram = computeWordLengthHistogram("C:/cygwin64/home/dziadzio/stl/hamlet.txt");
    std::cout << histogram["the"] << std::endl;
    std::cout << countWordsStartingWithLetter('d', histogram);
}
