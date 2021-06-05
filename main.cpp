#include<bits/stdc++.h>
#include "./include/DSA.hpp"

/**
 *
 * The main file 
 * Linked to the data structures and algorithms library
 */

int main() {
    srand(0);
    LinkedList<int> s;
    for(int i = 0; i < 10; i++) {
        s.add_last(i);
        s.add_first(i);
    }
    s.clear();
    s.add_first(10);
    while(!s.empty()) {
        std::cout << s.remove_first() <<" ";
    }
    std::cout << "\n";
    return 0;
}
