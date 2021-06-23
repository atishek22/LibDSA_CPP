#include "./include/DSA.hpp"

/**
 *
 * The main file 
 * Linked to the data structures and algorithms library
 */

int main() {
    HashTable<int, int> a;
    for(int i = 0; i < 10; i++) {
        a.insert(i, 2*i);
    }
    a.update(5, 15);
    for(int i = 0; i < 10; i++) {
        std::cout << a.get(i).value() << "\n";
    }
    a.clear();
    std::cout << a.size() << " " << a.empty() << "\n";
    return 0;
}
