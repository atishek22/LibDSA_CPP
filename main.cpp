#include "./include/DSA.hpp"

/**
 * The main file 
 * Linked to the data structures and algorithms library
 */

int main() {
    HashTableOA<int, int> a;
    for(int i = 0; i < 10; i++) {
        a.insert(i, 2*i);
    }
    std::cout << a.size() << "\n";
    for(int i = 0; i < 10; i++) {
        auto test = a.remove(i);
        std::cout << test.value_or(0) << "\n";
    }
    a.clear();
    std::cout << a.size() << " " << a.empty() << "\n";
    return 0;
}
