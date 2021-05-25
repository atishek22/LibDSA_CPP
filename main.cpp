#include<bits/stdc++.h>
#include "./include/DSA.hpp"

/**
 *
 * The main file 
 * Linked to the data structures and algorithms library
 */

int main() {
  srand(0);
  std::vector<int> v;
  for(int i = 0; i < 10; i++){
    v.push_back(i);
  }
  randomisedQuickSort(v, sorting::decreasingOrder<int>);
  for(int i = 0; i < 10; i++) {
    std::cout << v[i] << " ";
  }
  std::cout << "\n";
  return 0;
}
