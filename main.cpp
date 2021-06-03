#include<bits/stdc++.h>
#include "./include/DSA.hpp"

/**
 *
 * The main file 
 * Linked to the data structures and algorithms library
 */

int main() {
    srand(0);
    Queue<int> s;
    for(int i = 0; i < 10; i++) {
        s.enqueue(i);
    }
    s.clear();
    s.enqueue(10);
    while(!s.empty()) {
        std::cout << s.dequeue() <<" ";
    }
    std::cout << "\n";
    return 0;
}
