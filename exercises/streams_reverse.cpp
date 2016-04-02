#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <vector>

int main() {
//write file contents in reverse
    std::vector<char> fileContent;
    std::ifstream inFile("data.txt");
    std::istreambuf_iterator<char> inIter(inFile);
    std::istreambuf_iterator<char> eos;
    std::ostream_iterator<int> out(std::cout, ", ");

    while(inIter != eos)
        fileContent.push_back(*inIter++);
    for(std::vector<char>::reverse_iterator it = fileContent.rbegin(); it != fileContent.rend(); ++it)
        std::cout << *it;
    std::cout << std::endl;
}
