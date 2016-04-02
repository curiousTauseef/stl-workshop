#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <vector>

int main() {
//write file contents in ASCII
    std::ifstream file("data.txt");
    std::istreambuf_iterator<char> in(file);
    std::istreambuf_iterator<char> eof;
    while(in!=eof)
        *out = *in++;
    std::cout << std::endl;
}
