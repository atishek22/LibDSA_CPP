#include<bits/stdc++.h>
#include "./include/DSA.hpp"

/**
 *
 * The main file 
 * Linked to the data structures and algorithms library
 */

int main() {
    srand(0);
    Stack<int> s{10, 8, 10, 12 ,14};
    int len = s.size();
    for(int i = 0; i < len; i++) {
        std::cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
