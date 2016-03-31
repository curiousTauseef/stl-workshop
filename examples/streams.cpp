#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>

int main() {
//numeric iterator
    std::ostream_iterator<double> it(std::cout, " ");
    *it = 5.1;
    *it = 3.14;
    std::cout << std::endl;
//mixing iterators
    std::stringstream strStream;
    std::ostream_iterator<std::string> ssIt1(strStream, " ");
    std::ostream_iterator<double> ssIt2(strStream, "f ");
    ssIt1 = "Hello";
    ssIt1 = "STL";
    ssIt2 = 1;
    ssIt2 = 0.889;
    std::cout << strStream.str() << std::endl;
    std::cout << std::endl;
// writing to file
    std::ofstream outFile;
    outFile.open("out.txt");
    std::ostream_iterator<std::string> fstreamIt(outFile, " ");
    fstreamIt = "Here's";
    fstreamIt = "Johnny!";
    outFile.close();
//reading from file
    std::ifstream inFile;
    inFile >> std::noskipws;
    inFile.open("out.txt");
    std::istreambuf_iterator<char> inIter(inFile);
    std::istreambuf_iterator<char> eos;

    while(inIter != eos)
        std::cout << *inIter++;
    std::cout << std::endl;
//standard input
    std::istream_iterator<std::string> inCinIter(std::cin);
    std::istream_iterator<std::string> eos2;
    while(inCinIter != eos2)
        std::cout << *inCinIter++;
    std::cout << std::endl;
}
