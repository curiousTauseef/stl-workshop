#include<iostream>
#include<list>
#include<string>

template<typename Container>
void printContainer(const Container &c) {
    for(auto const &elem : c)
        std::cout << elem << " ";
    std::cout << std::endl;
}

struct Person {
    std::string name;
    bool operator <(const Person &other) {return this->name < other.name;}
    bool operator ==(const Person &other) {return this->name == other.name;}
    Person(std::string n) : name(n) {std::cout << "default c-tor" << std::endl;}
    Person(const Person &other) : name(other.name) {std::cout << "copy c-tor" << std::endl;}
    Person(Person &&other) : name(std::move(other.name)) {std::cout << "move c-tor" << std::endl;}
};

int main () {
//initialise
    std::list<int> lst = {1, 2, 3, 4};
    std::list<int> lst2 = {22, 22, 33, 55, 44, 44};
//iterate
    auto iter = lst.begin();
    std::advance(iter, 3);
    std::cout << *iter << std::endl;
//sort, merge, splice
    lst.sort();
    lst.merge(lst2);
    printContainer(lst);
    lst2.push_back(42);
    lst.splice(iter++, lst2);
    printContainer(lst);
//unique
    lst.sort();
    lst.unique();
    printContainer(lst);
//list of structs
    Person alice = {"Alice"};
    Person bob = {"Bob"};
    Person carol = {"Carol"};
    std::list<Person> personList = {bob, carol, alice, carol};
    personList.sort();
    personList.unique();
}
